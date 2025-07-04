/*
 * Copyright (c) 2024 Realtek Semiconductor, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef DRIVERS_ENTROPY_ENTROPY_RTS5817_H
#define DRIVERS_ENTROPY_ENTROPY_RTS5817_H

#define R_PUF_SYS_RNG_VERSION      (0x00)
#define R_PUF_SYS_RNG_FEATURE      (0x08)
#define R_PUF_SYS_RNG_STATUS       (0x10)
#define R_PUF_SYS_RNG_ENABLE       (0x20)
#define R_PUF_SYS_RNG_CONFIG       (0x24)
#define R_PUF_SYS_RNG_TEST_CFG0    (0x30)
#define R_PUF_SYS_RNG_TEST_CFG1    (0x38)
#define R_PUF_SYS_RNG_TEST_CFG2    (0x3c)
#define R_PUF_SYS_RNG_TEST_REPORT0 (0x40)
#define R_PUF_SYS_RNG_TEST_REPORT1 (0x44)
#define R_PUF_SYS_RNG_TEST_REPORT2 (0x50)
#define R_PUF_SYS_RNG_TEST_REPORT3 (0x54)
#define R_PUF_SYS_RNG_TEST_REPORT4 (0x58)
#define R_PUF_SYS_RNG_TEST_REPORT5 (0x5c)
#define R_PUF_SYS_RNG_TEST_REPORT6 (0x60)
#define R_PUF_SYS_RNG_TEST_REPORT7 (0x64)
#define R_PUF_SYS_RNG_FIFO_CLEAR   (0x6c)
#define R_PUF_SYS_RNG_DATA_OUT     (0x70)

/* Bits of R_PUF_SYS_RNG_VERSION (0x00000600) */

#define PUF_SYS_RNG_VERSION_OFFSET 0UL
#define PUF_SYS_RNG_VERSION_BITS   32UL
#define PUF_SYS_RNG_VERSION_MASK   (((1UL << 32UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_VERSION        (PUF_SYS_RNG_VERSION_MASK)

/* Bits of R_PUF_SYS_RNG_FEATURE (0x00000608) */

#define PUF_SYS_RNG_FEATURE_OFFSET 0UL
#define PUF_SYS_RNG_FEATURE_BITS   2UL
#define PUF_SYS_RNG_FEATURE_MASK   (((1UL << 2UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_FEATURE        (PUF_SYS_RNG_FEATURE_MASK)

/* Bits of R_PUF_SYS_RNG_STATUS (0x00000610) */

#define PUF_SYS_RNG_IDLE_OFFSET 0UL
#define PUF_SYS_RNG_IDLE_BITS   1UL
#define PUF_SYS_RNG_IDLE_MASK   (((1UL << 1UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_IDLE        (PUF_SYS_RNG_IDLE_MASK)

#define PUF_SYS_FIFO_CLEARED_OFFSET 1UL
#define PUF_SYS_FIFO_CLEARED_BITS   1UL
#define PUF_SYS_FIFO_CLEARED_MASK   (((1UL << 1UL) - 1UL) << 1UL)
#define PUF_SYS_FIFO_CLEARED        (PUF_SYS_FIFO_CLEARED_MASK)

#define PUF_SYS_ENTROPY_AVAILABLE_OFFSET 2UL
#define PUF_SYS_ENTROPY_AVAILABLE_BITS   1UL
#define PUF_SYS_ENTROPY_AVAILABLE_MASK   (((1UL << 1UL) - 1UL) << 2UL)
#define PUF_SYS_ENTROPY_AVAILABLE        (PUF_SYS_ENTROPY_AVAILABLE_MASK)

#define PUF_SYS_B_FIFO_AVAILABLE_OFFSET 4UL
#define PUF_SYS_B_FIFO_AVAILABLE_BITS   1UL
#define PUF_SYS_B_FIFO_AVAILABLE_MASK   (((1UL << 1UL) - 1UL) << 4UL)
#define PUF_SYS_B_FIFO_AVAILABLE        (PUF_SYS_B_FIFO_AVAILABLE_MASK)

#define PUF_SYS_A_FIFO_AVAILABLE_OFFSET 5UL
#define PUF_SYS_A_FIFO_AVAILABLE_BITS   1UL
#define PUF_SYS_A_FIFO_AVAILABLE_MASK   (((1UL << 1UL) - 1UL) << 5UL)
#define PUF_SYS_A_FIFO_AVAILABLE        (PUF_SYS_A_FIFO_AVAILABLE_MASK)

#define PUF_SYS_A_FIFO_FULL_OFFSET 6UL
#define PUF_SYS_A_FIFO_FULL_BITS   1UL
#define PUF_SYS_A_FIFO_FULL_MASK   (((1UL << 1UL) - 1UL) << 6UL)
#define PUF_SYS_A_FIFO_FULL        (PUF_SYS_A_FIFO_FULL_MASK)

#define PUF_SYS_RNG_IS_ENABLED_OFFSET 8UL
#define PUF_SYS_RNG_IS_ENABLED_BITS   1UL
#define PUF_SYS_RNG_IS_ENABLED_MASK   (((1UL << 1UL) - 1UL) << 8UL)
#define PUF_SYS_RNG_IS_ENABLED        (PUF_SYS_RNG_IS_ENABLED_MASK)

#define PUF_SYS_RNG_HEALTH_TEST_ACTIVE_OFFSET 9UL
#define PUF_SYS_RNG_HEALTH_TEST_ACTIVE_BITS   1UL
#define PUF_SYS_RNG_HEALTH_TEST_ACTIVE_MASK   (((1UL << 1UL) - 1UL) << 9UL)
#define PUF_SYS_RNG_HEALTH_TEST_ACTIVE        (PUF_SYS_RNG_HEALTH_TEST_ACTIVE_MASK)

#define PUF_SYS_GENERATING_RANDOM_DATA_OFFSET 10UL
#define PUF_SYS_GENERATING_RANDOM_DATA_BITS   1UL
#define PUF_SYS_GENERATING_RANDOM_DATA_MASK   (((1UL << 1UL) - 1UL) << 10UL)
#define PUF_SYS_GENERATING_RANDOM_DATA        (PUF_SYS_GENERATING_RANDOM_DATA_MASK)

#define PUF_SYS_RNG_HALTED_OFFSET 11UL
#define PUF_SYS_RNG_HALTED_BITS   1UL
#define PUF_SYS_RNG_HALTED_MASK   (((1UL << 1UL) - 1UL) << 11UL)
#define PUF_SYS_RNG_HALTED        (PUF_SYS_RNG_HALTED_MASK)

/* Bits of R_PUF_SYS_RNG_ENABLE (0x00000620) */

#define PUF_SYS_RNG_FUN_EN_OFFSET 0UL
#define PUF_SYS_RNG_FUN_EN_BITS   1UL
#define PUF_SYS_RNG_FUN_EN_MASK   (((1UL << 1UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_FUN_EN        (PUF_SYS_RNG_FUN_EN_MASK)

#define PUF_SYS_RNG_CLK_EN_OFFSET 1UL
#define PUF_SYS_RNG_CLK_EN_BITS   1UL
#define PUF_SYS_RNG_CLK_EN_MASK   (((1UL << 1UL) - 1UL) << 1UL)
#define PUF_SYS_RNG_CLK_EN        (PUF_SYS_RNG_CLK_EN_MASK)

#define PUF_SYS_RNG_OUT_EN_OFFSET 2UL
#define PUF_SYS_RNG_OUT_EN_BITS   1UL
#define PUF_SYS_RNG_OUT_EN_MASK   (((1UL << 1UL) - 1UL) << 2UL)
#define PUF_SYS_RNG_OUT_EN        (PUF_SYS_RNG_OUT_EN_MASK)

#define PUF_SYS_RNG_RPT_EN_OFFSET 3UL
#define PUF_SYS_RNG_RPT_EN_BITS   1UL
#define PUF_SYS_RNG_RPT_EN_MASK   (((1UL << 1UL) - 1UL) << 3UL)
#define PUF_SYS_RNG_RPT_EN        (PUF_SYS_RNG_RPT_EN_MASK)

#define PUF_SYS_RNG_ROT_EN_OFFSET 4UL
#define PUF_SYS_RNG_ROT_EN_BITS   1UL
#define PUF_SYS_RNG_ROT_EN_MASK   (((1UL << 1UL) - 1UL) << 4UL)
#define PUF_SYS_RNG_ROT_EN        (PUF_SYS_RNG_ROT_EN_MASK)

/* Bits of R_PUF_SYS_RNG_CONFIG (0x00000624) */

#define PUF_SYS_RNG_XOR_SEL_OFFSET 0UL
#define PUF_SYS_RNG_XOR_SEL_BITS   4UL
#define PUF_SYS_RNG_XOR_SEL_MASK   (((1UL << 4UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_XOR_SEL        (PUF_SYS_RNG_XOR_SEL_MASK)

#define PUF_SYS_RNG_BYP_COND_OFFSET 16UL
#define PUF_SYS_RNG_BYP_COND_BITS   1UL
#define PUF_SYS_RNG_BYP_COND_MASK   (((1UL << 1UL) - 1UL) << 16UL)
#define PUF_SYS_RNG_BYP_COND        (PUF_SYS_RNG_BYP_COND_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_CFG0 (0x00000630) */

#define PUF_SYS_RNG_TEST_WND_OFFSET 0UL
#define PUF_SYS_RNG_TEST_WND_BITS   16UL
#define PUF_SYS_RNG_TEST_WND_MASK   (((1UL << 16UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_TEST_WND        (PUF_SYS_RNG_TEST_WND_MASK)

#define PUF_SYS_RNG_ALERT_THRES_OFFSET 16UL
#define PUF_SYS_RNG_ALERT_THRES_BITS   16UL
#define PUF_SYS_RNG_ALERT_THRES_MASK   (((1UL << 16UL) - 1UL) << 16UL)
#define PUF_SYS_RNG_ALERT_THRES        (PUF_SYS_RNG_ALERT_THRES_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_CFG1 (0x00000638) */

#define PUF_SYS_RNG_THRES_H_RPTCNT_OFFSET 0UL
#define PUF_SYS_RNG_THRES_H_RPTCNT_BITS   16UL
#define PUF_SYS_RNG_THRES_H_RPTCNT_MASK   (((1UL << 16UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_THRES_H_RPTCNT        (PUF_SYS_RNG_THRES_H_RPTCNT_MASK)

#define PUF_SYS_RNG_THRES_H_RPTCNTS_OFFSET 16UL
#define PUF_SYS_RNG_THRES_H_RPTCNTS_BITS   16UL
#define PUF_SYS_RNG_THRES_H_RPTCNTS_MASK   (((1UL << 16UL) - 1UL) << 16UL)
#define PUF_SYS_RNG_THRES_H_RPTCNTS        (PUF_SYS_RNG_THRES_H_RPTCNTS_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_CFG2 (0x0000063c) */

#define PUF_SYS_RNG_THRES_H_ADPPPT_OFFSET 0UL
#define PUF_SYS_RNG_THRES_H_ADPPPT_BITS   16UL
#define PUF_SYS_RNG_THRES_H_ADPPPT_MASK   (((1UL << 16UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_THRES_H_ADPPPT        (PUF_SYS_RNG_THRES_H_ADPPPT_MASK)

#define PUF_SYS_RNG_THRES_L_ADPPPT_OFFSET 16UL
#define PUF_SYS_RNG_THRES_L_ADPPPT_BITS   16UL
#define PUF_SYS_RNG_THRES_L_ADPPPT_MASK   (((1UL << 16UL) - 1UL) << 16UL)
#define PUF_SYS_RNG_THRES_L_ADPPPT        (PUF_SYS_RNG_THRES_L_ADPPPT_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_REPORT0 (0x00000640) */

#define PUF_SYS_RNG_WTRMRK_H_RPTCNT_OFFSET 0UL
#define PUF_SYS_RNG_WTRMRK_H_RPTCNT_BITS   16UL
#define PUF_SYS_RNG_WTRMRK_H_RPTCNT_MASK   (((1UL << 16UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_WTRMRK_H_RPTCNT        (PUF_SYS_RNG_WTRMRK_H_RPTCNT_MASK)

#define PUF_SYS_RNG_WTRMRK_H_RPTCNTS_OFFSET 16UL
#define PUF_SYS_RNG_WTRMRK_H_RPTCNTS_BITS   16UL
#define PUF_SYS_RNG_WTRMRK_H_RPTCNTS_MASK   (((1UL << 16UL) - 1UL) << 16UL)
#define PUF_SYS_RNG_WTRMRK_H_RPTCNTS        (PUF_SYS_RNG_WTRMRK_H_RPTCNTS_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_REPORT1 (0x00000644) */

#define PUF_SYS_RNG_WTRMRK_H_ADPPPT_OFFSET 0UL
#define PUF_SYS_RNG_WTRMRK_H_ADPPPT_BITS   16UL
#define PUF_SYS_RNG_WTRMRK_H_ADPPPT_MASK   (((1UL << 16UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_WTRMRK_H_ADPPPT        (PUF_SYS_RNG_WTRMRK_H_ADPPPT_MASK)

#define PUF_SYS_RNG_WTRMRK_L_ADPPPT_OFFSET 16UL
#define PUF_SYS_RNG_WTRMRK_L_ADPPPT_BITS   16UL
#define PUF_SYS_RNG_WTRMRK_L_ADPPPT_MASK   (((1UL << 16UL) - 1UL) << 16UL)
#define PUF_SYS_RNG_WTRMRK_L_ADPPPT        (PUF_SYS_RNG_WTRMRK_L_ADPPPT_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_REPORT2 (0x00000650) */

#define PUF_SYS_RNG_TF_H_RPTCNT_OFFSET 0UL
#define PUF_SYS_RNG_TF_H_RPTCNT_BITS   32UL
#define PUF_SYS_RNG_TF_H_RPTCNT_MASK   (((1UL << 32UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_TF_H_RPTCNT        (PUF_SYS_RNG_TF_H_RPTCNT_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_REPORT3 (0x00000654) */

#define PUF_SYS_RNG_TF_H_RPTCNTS_OFFSET 0UL
#define PUF_SYS_RNG_TF_H_RPTCNTS_BITS   32UL
#define PUF_SYS_RNG_TF_H_RPTCNTS_MASK   (((1UL << 32UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_TF_H_RPTCNTS        (PUF_SYS_RNG_TF_H_RPTCNTS_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_REPORT4 (0x00000658) */

#define PUF_SYS_RNG_TF_H_ADPPPT_OFFSET 0UL
#define PUF_SYS_RNG_TF_H_ADPPPT_BITS   32UL
#define PUF_SYS_RNG_TF_H_ADPPPT_MASK   (((1UL << 32UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_TF_H_ADPPPT        (PUF_SYS_RNG_TF_H_ADPPPT_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_REPORT5 (0x0000065c) */

#define PUF_SYS_RNG_TF_L_ADPPPT_OFFSET 0UL
#define PUF_SYS_RNG_TF_L_ADPPPT_BITS   32UL
#define PUF_SYS_RNG_TF_L_ADPPPT_MASK   (((1UL << 32UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_TF_L_ADPPPT        (PUF_SYS_RNG_TF_L_ADPPPT_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_REPORT6 (0x00000660) */

#define PUF_SYS_RNG_FCNT_OFFSET 0UL
#define PUF_SYS_RNG_FCNT_BITS   16UL
#define PUF_SYS_RNG_FCNT_MASK   (((1UL << 16UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_FCNT        (PUF_SYS_RNG_FCNT_MASK)

/* Bits of R_PUF_SYS_RNG_TEST_REPORT7 (0x00000664) */

#define PUF_SYS_RNG_FCNT_H_RPTCNT_OFFSET 0UL
#define PUF_SYS_RNG_FCNT_H_RPTCNT_BITS   4UL
#define PUF_SYS_RNG_FCNT_H_RPTCNT_MASK   (((1UL << 4UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_FCNT_H_RPTCNT        (PUF_SYS_RNG_FCNT_H_RPTCNT_MASK)

#define PUF_SYS_RNG_FCNT_H_RPTCNTS_OFFSET 4UL
#define PUF_SYS_RNG_FCNT_H_RPTCNTS_BITS   4UL
#define PUF_SYS_RNG_FCNT_H_RPTCNTS_MASK   (((1UL << 4UL) - 1UL) << 4UL)
#define PUF_SYS_RNG_FCNT_H_RPTCNTS        (PUF_SYS_RNG_FCNT_H_RPTCNTS_MASK)

#define PUF_SYS_RNG_FCNT_H_ADPPPT_OFFSET 8UL
#define PUF_SYS_RNG_FCNT_H_ADPPPT_BITS   4UL
#define PUF_SYS_RNG_FCNT_H_ADPPPT_MASK   (((1UL << 4UL) - 1UL) << 8UL)
#define PUF_SYS_RNG_FCNT_H_ADPPPT        (PUF_SYS_RNG_FCNT_H_ADPPPT_MASK)

#define PUF_SYS_RNG_FCNT_L_ADPPPT_OFFSET 12UL
#define PUF_SYS_RNG_FCNT_L_ADPPPT_BITS   4UL
#define PUF_SYS_RNG_FCNT_L_ADPPPT_MASK   (((1UL << 4UL) - 1UL) << 12UL)
#define PUF_SYS_RNG_FCNT_L_ADPPPT        (PUF_SYS_RNG_FCNT_L_ADPPPT_MASK)

/* Bits of R_PUF_SYS_RNG_FIFO_CLEAR (0x0000066c) */

#define PUF_SYS_RNG_HT_CLR_OFFSET 0UL
#define PUF_SYS_RNG_HT_CLR_BITS   1UL
#define PUF_SYS_RNG_HT_CLR_MASK   (((1UL << 1UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_HT_CLR        (PUF_SYS_RNG_HT_CLR_MASK)

/* Bits of R_PUF_SYS_RNG_DATA_OUT (0x00000670) */

#define PUF_SYS_RNG_RN_DAT_OFFSET 0UL
#define PUF_SYS_RNG_RN_DAT_BITS   32UL
#define PUF_SYS_RNG_RN_DAT_MASK   (((1UL << 32UL) - 1UL) << 0UL)
#define PUF_SYS_RNG_RN_DAT        (PUF_SYS_RNG_RN_DAT_MASK)

#endif /* DRIVERS_ENTROPY_ENTROPY_RTS5817_H */
