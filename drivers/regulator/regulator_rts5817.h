/*
 * Copyright (c) 2024 Realtek Semiconductor, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_REGULATOR_REGULATOR_RTS5817_H_
#define ZEPHYR_DRIVERS_REGULATOR_REGULATOR_RTS5817_H_

#define DLINK_LDO_BASE_ADDR 0

#define R_LDO_TOP_POW      (DLINK_LDO_BASE_ADDR + 0X0000)
#define R_LDO_TOP_PD       (DLINK_LDO_BASE_ADDR + 0X0004)
#define R_LDO_TOP_TUNE_OCP (DLINK_LDO_BASE_ADDR + 0X0008)
#define R_LDO_TOP_REF      (DLINK_LDO_BASE_ADDR + 0X000C)
#define R_LDO_TOP_SR       (DLINK_LDO_BASE_ADDR + 0X0010)
#define R_LDO_TOP_VO       (DLINK_LDO_BASE_ADDR + 0X0014)
#define R_LDO_TOP_OC_SVIO  (DLINK_LDO_BASE_ADDR + 0X0018)
#define R_LDO_TOP_OC_SVA   (DLINK_LDO_BASE_ADDR + 0X001C)
#define R_LDO_TOP_INT      (DLINK_LDO_BASE_ADDR + 0X0020)
#define R_LDO_TOP_STATUS   (DLINK_LDO_BASE_ADDR + 0X0024)

/* Bits of R_LDO_TOP_POW (0X0000) */

#define POW_SVIO_OFFSET 0
#define POW_SVIO_BITS   2
#define POW_SVIO_MASK   (((1 << 2) - 1) << 0)
#define POW_SVIO        (POW_SVIO_MASK)

#define POW_SVA_OFFSET 2
#define POW_SVA_BITS   2
#define POW_SVA_MASK   (((1 << 2) - 1) << 2)
#define POW_SVA        (POW_SVA_MASK)

#define POW_LED_OFFSET 4
#define POW_LED_BITS   2
#define POW_LED_MASK   (((1 << 2) - 1) << 4)
#define POW_LED        (POW_LED_MASK)

#define POW_PWD_PUFF_OFFSET 6
#define POW_PWD_PUFF_BITS   1
#define POW_PWD_PUFF_MASK   (((1 << 1) - 1) << 6)
#define POW_PWD_PUFF        (POW_PWD_PUFF_MASK)

#define PUFF_ISO_OFFSET 7
#define PUFF_ISO_BITS   1
#define PUFF_ISO_MASK   (((1 << 1) - 1) << 7)
#define PUFF_ISO        (PUFF_ISO_MASK)

#define PUFF_ISO_OUT_OFFSET 8
#define PUFF_ISO_OUT_BITS   1
#define PUFF_ISO_OUT_MASK   (((1 << 1) - 1) << 8)
#define PUFF_ISO_OUT        (PUFF_ISO_OUT_MASK)

/* Bits of R_LDO_TOP_PD (0X0004) */

#define REG_PD_SVIO_OFFSET 0
#define REG_PD_SVIO_BITS   2
#define REG_PD_SVIO_MASK   (((1 << 2) - 1) << 0)
#define REG_PD_SVIO        (REG_PD_SVIO_MASK)

#define REG_PD_SVA_OFFSET 2
#define REG_PD_SVA_BITS   2
#define REG_PD_SVA_MASK   (((1 << 2) - 1) << 2)
#define REG_PD_SVA        (REG_PD_SVA_MASK)

#define REG_PD_LED_OFFSET 4
#define REG_PD_LED_BITS   2
#define REG_PD_LED_MASK   (((1 << 2) - 1) << 4)
#define REG_PD_LED        (REG_PD_LED_MASK)

#define REG_PD_CORE_OFFSET 6
#define REG_PD_CORE_BITS   2
#define REG_PD_CORE_MASK   (((1 << 2) - 1) << 6)
#define REG_PD_CORE        (REG_PD_CORE_MASK)

/* Bits of R_LDO_TOP_TUNE_OCP (0X0008) */

#define REG_TUNE_OCP_LVL_SVIO_OFFSET 0
#define REG_TUNE_OCP_LVL_SVIO_BITS   3
#define REG_TUNE_OCP_LVL_SVIO_MASK   (((1 << 3) - 1) << 0)
#define REG_TUNE_OCP_LVL_SVIO        (REG_TUNE_OCP_LVL_SVIO_MASK)

#define REG_TUNE_OCP_LVL_SVA_OFFSET 3
#define REG_TUNE_OCP_LVL_SVA_BITS   3
#define REG_TUNE_OCP_LVL_SVA_MASK   (((1 << 3) - 1) << 3)
#define REG_TUNE_OCP_LVL_SVA        (REG_TUNE_OCP_LVL_SVA_MASK)

#define REG_TUNE_OCP_EN_SVIO_OFFSET 8
#define REG_TUNE_OCP_EN_SVIO_BITS   1
#define REG_TUNE_OCP_EN_SVIO_MASK   (((1 << 1) - 1) << 8)
#define REG_TUNE_OCP_EN_SVIO        (REG_TUNE_OCP_EN_SVIO_MASK)

#define REG_TUNE_OCP_EN_SVA_OFFSET 9
#define REG_TUNE_OCP_EN_SVA_BITS   1
#define REG_TUNE_OCP_EN_SVA_MASK   (((1 << 1) - 1) << 9)
#define REG_TUNE_OCP_EN_SVA        (REG_TUNE_OCP_EN_SVA_MASK)

/* Bits of R_LDO_TOP_REF (0X000C) */

#define REG_TUNE_REF_SVIO_OFFSET 0
#define REG_TUNE_REF_SVIO_BITS   2
#define REG_TUNE_REF_SVIO_MASK   (((1 << 2) - 1) << 0)
#define REG_TUNE_REF_SVIO        (REG_TUNE_REF_SVIO_MASK)

#define REG_TUNE_REF_SVA_OFFSET 2
#define REG_TUNE_REF_SVA_BITS   2
#define REG_TUNE_REF_SVA_MASK   (((1 << 2) - 1) << 2)
#define REG_TUNE_REF_SVA        (REG_TUNE_REF_SVA_MASK)

#define REG_TUNE_REF_LED_OFFSET 4
#define REG_TUNE_REF_LED_BITS   2
#define REG_TUNE_REF_LED_MASK   (((1 << 2) - 1) << 4)
#define REG_TUNE_REF_LED        (REG_TUNE_REF_LED_MASK)

#define REG_TUNE_REF_CORE_OFFSET 6
#define REG_TUNE_REF_CORE_BITS   2
#define REG_TUNE_REF_CORE_MASK   (((1 << 2) - 1) << 6)
#define REG_TUNE_REF_CORE        (REG_TUNE_REF_CORE_MASK)

/* Bits of R_LDO_TOP_SR (0X0010) */

#define REG_TUNE_SR_SVIO_OFFSET 0
#define REG_TUNE_SR_SVIO_BITS   2
#define REG_TUNE_SR_SVIO_MASK   (((1 << 2) - 1) << 0)
#define REG_TUNE_SR_SVIO        (REG_TUNE_SR_SVIO_MASK)

#define REG_TUNE_SR_SVA_OFFSET 2
#define REG_TUNE_SR_SVA_BITS   2
#define REG_TUNE_SR_SVA_MASK   (((1 << 2) - 1) << 2)
#define REG_TUNE_SR_SVA        (REG_TUNE_SR_SVA_MASK)

#define REG_TUNE_SR_CORE_OFFSET 4
#define REG_TUNE_SR_CORE_BITS   2
#define REG_TUNE_SR_CORE_MASK   (((1 << 2) - 1) << 4)
#define REG_TUNE_SR_CORE        (REG_TUNE_SR_CORE_MASK)

/* Bits of R_LDO_TOP_VO (0X0014) */

#define REG_TUNE_VO_SVIO_OFFSET 0
#define REG_TUNE_VO_SVIO_BITS   5
#define REG_TUNE_VO_SVIO_MASK   (((1 << 5) - 1) << 0)
#define REG_TUNE_VO_SVIO        (REG_TUNE_VO_SVIO_MASK)

#define REG_TUNE_VO_SVA_OFFSET 8
#define REG_TUNE_VO_SVA_BITS   5
#define REG_TUNE_VO_SVA_MASK   (((1 << 5) - 1) << 8)
#define REG_TUNE_VO_SVA        (REG_TUNE_VO_SVA_MASK)

#define REG_TUNE_VO_LED_OFFSET 16
#define REG_TUNE_VO_LED_BITS   3
#define REG_TUNE_VO_LED_MASK   (((1 << 3) - 1) << 16)
#define REG_TUNE_VO_LED        (REG_TUNE_VO_LED_MASK)

#define REG_TUNE_VO_CORE_OFFSET 24
#define REG_TUNE_VO_CORE_BITS   5
#define REG_TUNE_VO_CORE_MASK   (((1 << 5) - 1) << 24)
#define REG_TUNE_VO_CORE        (REG_TUNE_VO_CORE_MASK)

/* Bits of R_LDO_TOP_OC_SVIO (0X0018) */

#define OC_POW_OFF_EN_SVIO_OFFSET 0
#define OC_POW_OFF_EN_SVIO_BITS   1
#define OC_POW_OFF_EN_SVIO_MASK   (((1 << 1) - 1) << 0)
#define OC_POW_OFF_EN_SVIO        (OC_POW_OFF_EN_SVIO_MASK)

#define OC_DEGLITCH_TIME_SVIO_OFFSET 1
#define OC_DEGLITCH_TIME_SVIO_BITS   2
#define OC_DEGLITCH_TIME_SVIO_MASK   (((1 << 2) - 1) << 1)
#define OC_DEGLITCH_TIME_SVIO        (OC_DEGLITCH_TIME_SVIO_MASK)

#define OC_DELAY_TIME_SVIO_OFFSET 3
#define OC_DELAY_TIME_SVIO_BITS   3
#define OC_DELAY_TIME_SVIO_MASK   (((1 << 3) - 1) << 3)
#define OC_DELAY_TIME_SVIO        (OC_DELAY_TIME_SVIO_MASK)

#define OC_EN_SVIO_OFFSET 6
#define OC_EN_SVIO_BITS   1
#define OC_EN_SVIO_MASK   (((1 << 1) - 1) << 6)
#define OC_EN_SVIO        (OC_EN_SVIO_MASK)

/* Bits of R_LDO_TOP_OC_SVA (0X001C) */

#define OC_POW_OFF_EN_SVA_OFFSET 0
#define OC_POW_OFF_EN_SVA_BITS   1
#define OC_POW_OFF_EN_SVA_MASK   (((1 << 1) - 1) << 0)
#define OC_POW_OFF_EN_SVA        (OC_POW_OFF_EN_SVA_MASK)

#define OC_DEGLITCH_TIME_SVA_OFFSET 1
#define OC_DEGLITCH_TIME_SVA_BITS   2
#define OC_DEGLITCH_TIME_SVA_MASK   (((1 << 2) - 1) << 1)
#define OC_DEGLITCH_TIME_SVA        (OC_DEGLITCH_TIME_SVA_MASK)

#define OC_DELAY_TIME_SVA_OFFSET 3
#define OC_DELAY_TIME_SVA_BITS   3
#define OC_DELAY_TIME_SVA_MASK   (((1 << 3) - 1) << 3)
#define OC_DELAY_TIME_SVA        (OC_DELAY_TIME_SVA_MASK)

#define OC_EN_SVA_OFFSET 6
#define OC_EN_SVA_BITS   1
#define OC_EN_SVA_MASK   (((1 << 1) - 1) << 6)
#define OC_EN_SVA        (OC_EN_SVA_MASK)

/* Bits of R_LDO_TOP_INT (0X0020) */

#define OC_DETECT_SVA_INT_OFFSET 0
#define OC_DETECT_SVA_INT_BITS   1
#define OC_DETECT_SVA_INT_MASK   (((1 << 1) - 1) << 0)
#define OC_DETECT_SVA_INT        (OC_DETECT_SVA_INT_MASK)

#define OC_DETECT_SVIO_INT_OFFSET 1
#define OC_DETECT_SVIO_INT_BITS   1
#define OC_DETECT_SVIO_INT_MASK   (((1 << 1) - 1) << 1)
#define OC_DETECT_SVIO_INT        (OC_DETECT_SVIO_INT_MASK)

/* Bits of R_LDO_TOP_STATUS (0X0024) */

#define OC_POW_SVA_OFFSET 0
#define OC_POW_SVA_BITS   1
#define OC_POW_SVA_MASK   (((1 << 1) - 1) << 0)
#define OC_POW_SVA        (OC_POW_SVA_MASK)

#define OC_POW_SVIO_OFFSET 1
#define OC_POW_SVIO_BITS   1
#define OC_POW_SVIO_MASK   (((1 << 1) - 1) << 1)
#define OC_POW_SVIO        (OC_POW_SVIO_MASK)

#endif /* ZEPHYR_DRIVERS_REGULATOR_REGULATOR_RTS5817_H_ */
