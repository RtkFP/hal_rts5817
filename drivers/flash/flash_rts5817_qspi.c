/*
 * Copyright (c) 2024 Realtek Semiconductor, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/drivers/clock_control.h>
#include <zephyr/logging/log.h>
#include <zephyr/cache.h>
#include "zephyr/device.h"
#include "flash_rts5817_qspi_reg.h"
#include "flash_rts5817_qspi.h"

#define DT_DRV_COMPAT realtek_rts5817_qspi

LOG_MODULE_REGISTER(flash_rts5817_qspi, CONFIG_FLASH_LOG_LEVEL);

#define CACHE_SPI_AUTOMODE_TRANSFER_MODE_OFFSET 8
#define CACHE_A_SPI_DUM_BIT_NUM_OFFSET          16
#define ERASE_SECTOR_SIZE                       0x1000

struct flash_rts5817_qspi_config {
	mem_addr_t base;
	mem_addr_t cs_reg;
	mem_addr_t cmd_reg;
	const struct device *clock_dev;
	clock_control_subsys_t clock_subsys;
};

struct flash_rts5817_qspi_data {
	const spi_flash_params *flash;
	uint8_t flash_type;
#if defined(CONFIG_FLASH_PAGE_LAYOUT)
	struct flash_pages_layout layout;
#endif
};

static inline uint8_t flash_get_type(const struct device *dev)
{
	const struct flash_rts5817_qspi_config *dev_conf = dev->config;

	return sys_read8(dev_conf->cs_reg);
}

static inline uint32_t flash_get_automode(const struct device *dev)
{
	const struct flash_rts5817_qspi_config *dev_conf = dev->config;

	return sys_read32(dev_conf->cmd_reg);
}

static inline void flash_set_automode(const struct device *dev, uint32_t data)
{
	const struct flash_rts5817_qspi_config *dev_conf = dev->config;

	sys_write32(data, dev_conf->cmd_reg);
}

static inline uint32_t rts_fp_flash_read_reg(const struct device *dev, uint32_t offset)
{
	const struct flash_rts5817_qspi_config *dev_conf = dev->config;

	return sys_read32(dev_conf->base + offset);
}

static inline void rts_fp_flash_write_reg(const struct device *dev, uint32_t data, uint32_t offset)
{
	const struct flash_rts5817_qspi_config *dev_conf = dev->config;

	sys_write32(data, dev_conf->base + offset);
}

static int check_transfer_end(const struct device *dev)
{
	const struct flash_rts5817_qspi_config *dev_conf = dev->config;
	uint32_t timeout = 5000;

	while (timeout) {
		if (sys_test_bit(dev_conf->base + R_SPI_COM_TRANSFER, SPI_WB_IDLE_OFFSET)) {
			if (!sys_test_bit(dev_conf->base + R_SPI_COM_TRANSFER,
					  SPI_WB_TIMEOUT_OFFSET)) {
				return 0;
			}
		}
		k_busy_wait(500);
		timeout--;
	}
	return -ETIMEDOUT;
}

static int rts_fp_qspi_transfer(const struct device *dev, uint32_t dma_addr, size_t length,
				uint8_t cmd_nums, uint8_t dma_dir)
{
	rts_fp_flash_write_reg(dev, dma_dir, R_SPI_WB_DMA_DIR);
	rts_fp_flash_write_reg(dev, dma_addr, R_SPI_WB_DMA_ADDR);
	rts_fp_flash_write_reg(dev, length, R_SPI_WB_DMA_LEN);

	rts_fp_flash_write_reg(dev, 0xFF, R_SPI_TOP_CTL);
	rts_fp_flash_write_reg(dev, SPI_WB_START | cmd_nums, R_SPI_COM_TRANSFER);

	return check_transfer_end(dev);
}

/* write enable */
static void rts_fp_spi_write_enable_using_cmd1(const struct device *dev, uint32_t addr)
{
	rts_fp_flash_write_reg(dev, SF_WREN, R_SPI_SUB1_COMMAND);
	rts_fp_flash_write_reg(dev, addr, R_SPI_SUB1_ADDR);
	rts_fp_flash_write_reg(dev, SPI_C_MODE0, R_SPI_SUB1_MODE);
}

/* polling status ACK */
static void rts_fp_spi_polling_status_using_cmd3(const struct device *dev, uint32_t addr)
{
	rts_fp_flash_write_reg(dev, SF_RDSR, R_SPI_SUB3_COMMAND);
	rts_fp_flash_write_reg(dev, addr, R_SPI_SUB3_ADDR);
	rts_fp_flash_write_reg(dev, SPI_POLLING_MODE0, R_SPI_SUB3_MODE);
}

static int rts_fp_flash_write_status(const struct device *dev, uint8_t cmd, uint16_t value,
				     uint8_t len, uint32_t addr)
{
	struct flash_rts5817_qspi_data *dev_data = dev->data;

	sys_cache_data_flush_range(&value, len);
	/* write enable */
	rts_fp_flash_write_reg(dev, dev_data->flash->sr_wren_command, R_SPI_SUB1_COMMAND);
	rts_fp_flash_write_reg(dev, addr, R_SPI_SUB1_ADDR);
	rts_fp_flash_write_reg(dev, SPI_C_MODE0, R_SPI_SUB1_MODE);

	/* write status */
	rts_fp_flash_write_reg(dev, cmd, R_SPI_SUB2_COMMAND);
	rts_fp_flash_write_reg(dev, addr, R_SPI_SUB2_ADDR);
	rts_fp_flash_write_reg(dev, len, R_SPI_SUB2_LENGTH);
	rts_fp_flash_write_reg(dev, SPI_CDO_MODE0, R_SPI_SUB2_MODE);

	/* polling status ACK */
	rts_fp_spi_polling_status_using_cmd3(dev, addr);
	return rts_fp_qspi_transfer(dev, (uint32_t)&value, len, SPI_COM_TRANSFER_NUM_3,
				    DTCM_TO_SPI);
}

static int rts_fp_flash_write_protect(const struct device *dev, uint8_t enable, uint32_t addr)
{
	struct flash_rts5817_qspi_data *dev_data = dev->data;
	uint16_t value = 0;
	int ret;

	if (enable == true) {
		value = 0x1C | dev_data->flash->location_qe;
	} else {
		value = 0x00 | dev_data->flash->location_qe;
	}

	switch (dev_data->flash->str_rw_type) {
	case SREG1_R1_W1:
		ret = rts_fp_flash_write_status(dev, SF_WRSR, value, 1, addr);
		break;
	case SREG2_R2_W1:
		ret = rts_fp_flash_write_status(dev, SF_WRSR, value, 2, addr);
		break;
	case SREG2_R2_W2:
		ret = rts_fp_flash_write_status(dev, SF_WRSR, value, 1, addr);
		if (ret) {
			return ret;
		}
		ret = rts_fp_flash_write_status(dev, SF_WRSR_H, value >> 8, 1, addr);
		break;
	default:
		ret = -EINVAL;
		break;
	}
	return ret;
}
static void __attribute((aligned(32), noinline)) set_cache_spi_automode(const struct device *dev,
									uint32_t auto_mode)
{
	struct flash_rts5817_qspi_data *dev_data = dev->data;
	uint32_t reg;

	reg = rts_fp_flash_read_reg(dev, R_SPI_TOP_CTL);
	rts_fp_flash_write_reg(dev, (reg & ~SPI_U_DUM_BIT_NUM_MASK) | dev_data->flash->dummy_cycle,
			       R_SPI_TOP_CTL);
	flash_set_automode(dev, auto_mode);
}

static void rts_fp_spi_set_automode(const struct device *dev)
{
	struct flash_rts5817_qspi_data *dev_data = dev->data;
	uint32_t auto_mode = 0;

	auto_mode |= dev_data->flash->dummy_cycle << CACHE_A_SPI_DUM_BIT_NUM_OFFSET;
	auto_mode |= dev_data->flash->read_mode << CACHE_SPI_AUTOMODE_TRANSFER_MODE_OFFSET;
	switch (dev_data->flash->read_mode) {
	case SPI_FAST_READ_DUAL_OUT_MODE:
		auto_mode |= SF_FAST_READ_DUAL_OUT;
		break;
	case SPI_FAST_READ_QUAD_OUT_MODE:
		auto_mode |= SF_FAST_READ_QUAD_OUT;
		break;
	case SPI_FAST_READ_DUAL_INOUT_MODE:
		auto_mode |= SF_FAST_READ_DUAL_INOUT;
		break;
	case SPI_FAST_READ_QUAD_INOUT_MODE:
		auto_mode |= SF_FAST_READ_QUAD_INOUT;
	default:
		auto_mode |= SF_FAST_READ_DUAL_OUT;
		break;
	}
	set_cache_spi_automode(dev, auto_mode);
}

static int rts_fp_read_jedec_id(const struct device *dev, uint8_t *id)
{
	if (id == NULL) {
		return -EINVAL;
	}
	sys_cache_data_flush_and_invd_range(id, 3);

	rts_fp_flash_write_reg(dev, SF_READID, R_SPI_SUB1_COMMAND);
	rts_fp_flash_write_reg(dev, SPI_CDI_MODE0, R_SPI_SUB1_MODE);
	rts_fp_flash_write_reg(dev, 3, R_SPI_SUB1_LENGTH);

	return rts_fp_qspi_transfer(dev, (uint32_t)id, 3, SPI_COM_TRANSFER_NUM_1, SPI_TO_DTCM);
}

static int flash_read_align(const struct device *dev, off_t addr, size_t size, uint8_t *data)
{
	uint8_t read_mode;
	uint8_t cmd;

	read_mode = (flash_get_automode(dev) >> CACHE_SPI_AUTOMODE_TRANSFER_MODE_OFFSET) & 0xFF;
	switch (read_mode) {
	case SPI_FAST_READ_DUAL_OUT_MODE:
		cmd = SF_FAST_READ_DUAL_OUT;
		break;
	case SPI_FAST_READ_QUAD_OUT_MODE:
		cmd = SF_FAST_READ_QUAD_OUT;
		break;
	case SPI_FAST_READ_DUAL_INOUT_MODE:
		cmd = SF_FAST_READ_DUAL_INOUT;
		break;
	case SPI_FAST_READ_QUAD_INOUT_MODE:
		cmd = SF_FAST_READ_QUAD_INOUT;
		break;
	default:
		return -EINVAL;
	}
	sys_cache_data_flush_and_invd_range(data, size);

	rts_fp_flash_write_reg(dev, cmd, R_SPI_SUB1_COMMAND);
	rts_fp_flash_write_reg(dev, read_mode, R_SPI_SUB1_MODE);
	rts_fp_flash_write_reg(dev, addr, R_SPI_SUB1_ADDR);
	rts_fp_flash_write_reg(dev, size, R_SPI_SUB1_LENGTH);
	return rts_fp_qspi_transfer(dev, (uint32_t)data, size, SPI_COM_TRANSFER_NUM_1, SPI_TO_DTCM);
}

static int flash_rts5817_qspi_read(const struct device *dev, off_t addr, void *data, size_t size)
{
	uint8_t __aligned(32) temp_buf[32];
	uint16_t temp_len;
	int ret;

	temp_len = 32 - ((uint32_t)data % 32);
	if (temp_len != 32) {
		if (size < temp_len) {
			temp_len = size;
		}
		ret = flash_read_align(dev, addr, temp_len, temp_buf);
		if (ret) {
			return ret;
		}
		memcpy(data, temp_buf, temp_len);
		size -= temp_len;
		addr += temp_len;
		data = (uint8_t *)data + temp_len;
	}

	temp_len = (size >> 5) << 5;
	if (temp_len) {
		ret = flash_read_align(dev, addr, temp_len, data);
		if (ret) {
			return ret;
		}
		size -= temp_len;
		addr += temp_len;
		data = (uint8_t *)data + temp_len;
	}

	if (size) {
		ret = flash_read_align(dev, addr, size, temp_buf);
		if (ret) {
			return ret;
		}
		memcpy(data, temp_buf, size);
	}
	return 0;
}

static int flash_page_program(const struct device *dev, uint32_t offset, uint16_t len,
			      const uint8_t *data)
{
	sys_cache_data_flush_range((void *)data, len);

	rts_fp_spi_write_enable_using_cmd1(dev, offset);

	/* page program */
	rts_fp_flash_write_reg(dev, 0x02, R_SPI_SUB2_COMMAND);
	rts_fp_flash_write_reg(dev, offset, R_SPI_SUB2_ADDR);
	rts_fp_flash_write_reg(dev, len, R_SPI_SUB2_LENGTH);
	rts_fp_flash_write_reg(dev, SPI_CADO_MODE0, R_SPI_SUB2_MODE);

	rts_fp_spi_polling_status_using_cmd3(dev, (uint32_t)offset);
	return rts_fp_qspi_transfer(dev, (uint32_t)data, len, SPI_COM_TRANSFER_NUM_3, DTCM_TO_SPI);
}

static int flash_rts5817_qspi_write(const struct device *dev, off_t offset, const void *data,
				    size_t len)
{
	struct flash_rts5817_qspi_data *dev_data = dev->data;
	uint32_t addr = (uint32_t)offset;
	uint16_t page_len;
	int ret;

	if (offset + len > dev_data->flash->flash_size) {
		return -EINVAL;
	}
	rts_fp_flash_write_protect(dev, false, addr);
	while (len) {
		page_len = 256 - (offset & 0xFF);
		if (len < page_len) {
			page_len = len;
		}

		ret = flash_page_program(dev, offset, page_len, (const uint8_t *)data);
		if (ret) {
			LOG_ERR("page program err %d", ret);
			return ret;
		}
		data = (const uint8_t *)data + page_len;
		offset += page_len;
		len -= page_len;
	}
	rts_fp_flash_write_protect(dev, true, addr);
	return ret;
}

static int flash_sector_erase(const struct device *dev, off_t offset)
{
	/* write enable */
	rts_fp_spi_write_enable_using_cmd1(dev, (uint32_t)offset);

	rts_fp_flash_write_reg(dev, SF_SECT_ERASE, R_SPI_SUB2_COMMAND);
	rts_fp_flash_write_reg(dev, offset, R_SPI_SUB2_ADDR);
	rts_fp_flash_write_reg(dev, SPI_CA_MODE0, R_SPI_SUB2_MODE);

	rts_fp_spi_polling_status_using_cmd3(dev, (uint32_t)offset);

	return rts_fp_qspi_transfer(dev, 0, 0, SPI_COM_TRANSFER_NUM_3, SPI_TO_DTCM);
}

static int flash_rts5817_qspi_erase(const struct device *dev, off_t offset, size_t size)
{
	struct flash_rts5817_qspi_data *dev_data = dev->data;
	uint32_t addr = (uint32_t)offset;
	int ret;

	if (offset < 0 || offset + size > dev_data->flash->flash_size) {
		return -EINVAL;
	}

	if (size % 0x1000) {
		return -EINVAL;
	}
	rts_fp_flash_write_protect(dev, false, addr);
	while (size) {
		ret = flash_sector_erase(dev, offset);
		if (ret) {
			return ret;
		}
		offset += 0x1000;
		size -= 0x1000;
	}
	rts_fp_flash_write_protect(dev, true, addr);
	return 0;
}

static const struct flash_parameters flash_rts5817_qspi_parameters = {.write_block_size = 1,
								      .erase_value = 0xff};

static const struct flash_parameters *flash_rts5817_qspi_get_parameters(const struct device *dev)
{
	ARG_UNUSED(dev);

	return &flash_rts5817_qspi_parameters;
}

#if defined(CONFIG_FLASH_PAGE_LAYOUT)
static void flash_rts5817_qspi_pages_layout(const struct device *dev,
					    const struct flash_pages_layout **layout,
					    size_t *layout_size)
{
	struct flash_rts5817_qspi_data *dev_data = dev->data;

	*layout = &dev_data->layout;
	*layout_size = 1;
}
#endif

static const struct flash_driver_api flash_rts5817_qspi_driver_api = {
	.read = flash_rts5817_qspi_read,
	.write = flash_rts5817_qspi_write,
	.erase = flash_rts5817_qspi_erase,
	.get_parameters = flash_rts5817_qspi_get_parameters,
#if defined(CONFIG_FLASH_PAGE_LAYOUT)
	.page_layout = flash_rts5817_qspi_pages_layout,
#endif
};

static int flash_rts5817_qspi_init(const struct device *dev)
{
	const struct flash_rts5817_qspi_config *dev_cfg = dev->config;
	struct flash_rts5817_qspi_data *dev_data = dev->data;
	const spi_flash_params *sf_table = NULL;
	clock_control_subsys_rate_t rate = (clock_control_subsys_rate_t)120000000;
	uint32_t id_read;
	uint8_t i;
	int ret;

	uint8_t __aligned(32) jedec_id[3];

	/* clock */
	if (clock_control_set_rate(dev_cfg->clock_dev, dev_cfg->clock_subsys, rate) != 0) {
		ret = -EINVAL;
		return ret;
	}

	/* Devider is set to 0, so default ck is 60MHz */
	rts_fp_flash_write_reg(dev, 0x0, R_SPI_CLK_DIVIDER);

	LOG_DBG("flash init clock finished");
	/* judge flash type & id */
	if (flash_get_type(dev) == EXT_FLASH) {
		sf_table = spi_ext_flash_params_table;
		dev_data->flash_type = EXT_FLASH;
		dev_data->flash = &spi_ext_flash_params_table[SUPPORT_FLASH_NUM];
	} else {
		sf_table = spi_mcm_flash_params_table;
		dev_data->flash_type = MCM_FLASH;
		dev_data->flash = &spi_mcm_flash_params_table[SUPPORT_FLASH_NUM];
	}

	/* read flash id */
	ret = rts_fp_read_jedec_id(dev, jedec_id);
	if (ret) {
		LOG_ERR("%s: %d err %d\n", __func__, __LINE__, ret);
		return ret;
	}

	id_read = (jedec_id[0] << 16 | jedec_id[1] << 8 | jedec_id[2]);
	LOG_DBG("%s: %d flash id  %x\n", __func__, __LINE__, id_read);
	if (id_read == NOFLASH) {
		return -ENXIO;
	}

	for (i = 0; i < SUPPORT_FLASH_NUM; i++) {
		if (sf_table[i].device_id == id_read) {
			break;
		}
	}
	dev_data->flash = &sf_table[i];
	dev_data->layout.pages_size = ERASE_SECTOR_SIZE; /* sector erase 4K */
	dev_data->layout.pages_count = dev_data->flash->flash_size / ERASE_SECTOR_SIZE;

	ret = rts_fp_flash_write_protect(dev, true, 0);
	rts_fp_spi_set_automode(dev);
	LOG_DBG("flash init finished");
	return ret;
}

static const struct flash_rts5817_qspi_config flash_rts5817_qspi_cfg = {
	.base = DT_INST_REG_ADDR(0),
	.cs_reg = DT_INST_REG_ADDR_BY_IDX(0, 1),
	.cmd_reg = DT_INST_REG_ADDR_BY_IDX(0, 2),
	.clock_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(0)),
	.clock_subsys = (clock_control_subsys_t)DT_INST_PHA(0, clocks, clkid),
};

static struct flash_rts5817_qspi_data flash_rts5817_qspi_dev_data;

DEVICE_DT_INST_DEFINE(0, &flash_rts5817_qspi_init, NULL, &flash_rts5817_qspi_dev_data,
		      &flash_rts5817_qspi_cfg, POST_KERNEL, CONFIG_FLASH_INIT_PRIORITY,
		      &flash_rts5817_qspi_driver_api);
