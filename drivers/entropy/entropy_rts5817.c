/*
 * Copyright (c) 2024 Realtek Semiconductor, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT realtek_rts5817_trng

#include <zephyr/device.h>
#include <zephyr/drivers/entropy.h>
#include <errno.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <soc.h>
#include <string.h>
#include "entropy_rts5817.h"
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(entropy_rts5817, CONFIG_ENTROPY_LOG_LEVEL);

struct trng_rts5817_cfg {
	mem_addr_t regs;
};

static int entropy_rts5817_get_entropy(const struct device *dev, uint8_t *buffer, uint16_t length)
{
	const struct trng_rts5817_cfg *cfg = dev->config;
	mem_addr_t regs = cfg->regs;
	union {
		uint32_t dword;
		uint8_t bytes[4];
	} rngdata;
	uint32_t rngstatus = 0;
	uint32_t offset = 0;
	uint32_t ret = 0;

	if ((buffer == NULL) || (length == 0)) {
		return -EINVAL;
	}

	sys_write32(0x20000, regs + R_PUF_SYS_RNG_CONFIG);
	sys_write32(PUF_SYS_RNG_FUN_EN | PUF_SYS_RNG_CLK_EN, regs + R_PUF_SYS_RNG_ENABLE);

	if (!WAIT_FOR((sys_read32(regs + R_PUF_SYS_RNG_STATUS) & PUF_SYS_RNG_IS_ENABLED) == 0x0,
		      1000, NULL)) {
		LOG_ERR("RNG enable timeout!");
		ret = -ETIMEDOUT;
		goto exit;
	}

	if (!WAIT_FOR((sys_read32(regs + R_PUF_SYS_RNG_STATUS) & PUF_SYS_RNG_HEALTH_TEST_ACTIVE) ==
			      0x0,
		      1000, NULL)) {
		LOG_ERR("RNG health test timeout!");
		ret = -ETIMEDOUT;
		goto exit;
	}

	rngstatus = sys_read32(regs + R_PUF_SYS_RNG_STATUS);

	if ((rngstatus & PUF_SYS_RNG_HALTED) == PUF_SYS_RNG_HALTED) {
		/* enable rng report */
		sys_write32(PUF_SYS_RNG_FUN_EN, regs + R_PUF_SYS_RNG_ENABLE);

		LOG_DBG("PUF RNG Report:\n");
		LOG_DBG("R_PUF_SYS_RNG_TEST_REPORT0:%x\n",
			sys_read32(regs + R_PUF_SYS_RNG_TEST_REPORT0));
		LOG_DBG("R_PUF_SYS_RNG_TEST_REPORT1:%x\n",
			sys_read32(regs + R_PUF_SYS_RNG_TEST_REPORT1));
		LOG_DBG("R_PUF_SYS_RNG_TEST_REPORT2:%x\n",
			sys_read32(regs + R_PUF_SYS_RNG_TEST_REPORT2));
		LOG_DBG("R_PUF_SYS_RNG_TEST_REPORT3:%x\n",
			sys_read32(regs + R_PUF_SYS_RNG_TEST_REPORT3));
		LOG_DBG("R_PUF_SYS_RNG_TEST_REPORT4:%x\n",
			sys_read32(regs + R_PUF_SYS_RNG_TEST_REPORT4));
		LOG_DBG("R_PUF_SYS_RNG_TEST_REPORT5:%x\n",
			sys_read32(regs + R_PUF_SYS_RNG_TEST_REPORT5));
		LOG_DBG("R_PUF_SYS_RNG_TEST_REPORT6:%x\n",
			sys_read32(regs + R_PUF_SYS_RNG_TEST_REPORT6));
		LOG_DBG("R_PUF_SYS_RNG_TEST_REPORT7:%x\n",
			sys_read32(regs + R_PUF_SYS_RNG_TEST_REPORT7));

		sys_write32(PUF_SYS_RNG_CLK_EN, regs + R_PUF_SYS_RNG_ENABLE);
		sys_write32(PUF_SYS_RNG_HT_CLR, regs + R_PUF_SYS_RNG_FIFO_CLEAR);

		if (!WAIT_FOR((sys_read32(regs + R_PUF_SYS_RNG_STATUS) & PUF_SYS_FIFO_CLEARED) ==
				      0x0,
			      1000, NULL)) {
			LOG_ERR("RNG health test timeout!");
			ret = -ETIMEDOUT;
			goto exit;
		}

		/* Try again */
		sys_write32(0x20000, regs + R_PUF_SYS_RNG_CONFIG);
		sys_write32(PUF_SYS_RNG_FUN_EN | PUF_SYS_RNG_CLK_EN, regs + R_PUF_SYS_RNG_ENABLE);

		if (!WAIT_FOR((sys_read32(regs + R_PUF_SYS_RNG_STATUS) & PUF_SYS_RNG_IS_ENABLED) ==
				      0x0,
			      1000, k_yield())) {
			LOG_ERR("RNG enable timeout!");
			ret = -ETIMEDOUT;
			goto exit;
		}

		if (!WAIT_FOR((sys_read32(regs + R_PUF_SYS_RNG_STATUS) &
			       PUF_SYS_RNG_HEALTH_TEST_ACTIVE) == 0x0,
			      1000, k_yield())) {
			LOG_ERR("RNG health test timeout!");
			ret = -ETIMEDOUT;
			goto exit;
		}

		rngstatus = sys_read32(regs + R_PUF_SYS_RNG_STATUS);
		if ((rngstatus & PUF_SYS_RNG_HALTED) == PUF_SYS_RNG_HALTED) {
			/* halted agagin */
			LOG_ERR("Cannot get random data from %s!", dev->name);
			ret = -EIO;
			goto exit;
		}
	}

	if ((rngstatus & PUF_SYS_GENERATING_RANDOM_DATA) == PUF_SYS_GENERATING_RANDOM_DATA) {
		/* Collect rng data */
		while (offset < length) {
			rngdata.dword = sys_read32(regs + R_PUF_SYS_RNG_DATA_OUT);

			if ((length - offset) < 4) {
				memcpy(&buffer[offset], rngdata.bytes, length - offset);
				offset += length - offset;
			} else {
				memcpy(&buffer[offset], rngdata.bytes, 4);
				offset += 4U;
			}
		}
	} else {
		LOG_ERR("Cannot get random data from %s!", dev->name);
		ret = -EIO;
	}

exit:
	sys_write32(PUF_SYS_RNG_CLK_EN, regs + R_PUF_SYS_RNG_ENABLE);
	return ret;
}

static int entropy_rts5817_init(const struct device *dev)
{
	return 0;
}

static const struct entropy_driver_api entropy_rts5817_api = {
	.get_entropy = entropy_rts5817_get_entropy, .get_entropy_isr = NULL};

static const struct trng_rts5817_cfg trng_rts5817_cfg = {
	.regs = (mem_addr_t)DT_INST_REG_ADDR(0),
};

DEVICE_DT_INST_DEFINE(0, entropy_rts5817_init, NULL, NULL, &trng_rts5817_cfg, PRE_KERNEL_1,
		      CONFIG_ENTROPY_INIT_PRIORITY, &entropy_rts5817_api);
