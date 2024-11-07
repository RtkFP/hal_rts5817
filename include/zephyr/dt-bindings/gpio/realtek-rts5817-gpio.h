/*
 * Copyright (c) 2024 Realtek Semiconductor, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_GPIO_RTS5817_GPIO_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_GPIO_RTS5817_GPIO_H_

#define GPIO_CACHE_CS2  0
#define GPIO_SSI_M_MISO 4
#define GPIO_SSI_M_MOSI 5
#define GPIO_SSI_M_CS   6
#define GPIO_SSI_M_SCK  7
#define GPIO_SCL0       8
#define GPIO_SDA0       9
#define GPIO_SCL2       10
#define GPIO_SDA2       11
#define GPIO_SCL1       12
#define GPIO_SDA1       13
#define GPIO_SSI_S_MISO 14
#define GPIO_SSI_S_MOSI 15
#define GPIO_SSI_S_CS   16
#define GPIO_SSI_S_SCK  17
#define GPIO_GPIO14     18
#define GPIO_GPIO15     19
#define GPIO_AL0        20
#define GPIO_AL1        21
#define GPIO_AL2        22
#define GPIO_SNR_RST    23
#define GPIO_SNR_CS     24
#define GPIO_SNR_GPIO   25
#define GPI_WAKE1       26
#define GPI_WAKE2       27

/* Note: Bits 15 downto 8 are reserved for SoC specific flags. */
#define GPIO_POWER_3V3 (1 << 8)
#define GPIO_POWER_1V8 (1 << 9)

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_GPIO_RTS5817_GPIO_H_ */
