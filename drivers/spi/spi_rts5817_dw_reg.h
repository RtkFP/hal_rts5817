/*
 * Copyright (c) 2024 Realtek Semiconductor, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_SPI_SPI_RTS5817_DW_REG_H_
#define ZEPHYR_DRIVERS_SPI_SPI_RTS5817_DW_REG_H_

#define R_SSI_CTRLR0        (0X0000)
#define R_SSI_CTRLR1        (0X0004)
#define R_SSI_SSIENR        (0X0008)
#define R_SSI_MWCR          (0X000C)
#define R_SSI_SER           (0X0010)
#define R_SSI_BAUDR         (0X0014)
#define R_SSI_TXFTLR        (0X0018)
#define R_SSI_RXFTLR        (0X001C)
#define R_SSI_TXFLR         (0X0020)
#define R_SSI_RXFLR         (0X0024)
#define R_SSI_SR            (0X0028)
#define R_SSI_IMR           (0X002C)
#define R_SSI_ISR           (0X0030)
#define R_SSI_RISR          (0X0034)
#define R_SSI_TXOICR        (0X0038)
#define R_SSI_RXOICR        (0X003C)
#define R_SSI_RXUICR        (0X0040)
#define R_SSI_MSTICR        (0X0044)
#define R_SSI_ICR           (0X0048)
#define R_SSI_DMACR         (0X004C)
#define R_SSI_DMATDLR       (0X0050)
#define R_SSI_DMARDLR       (0X0054)
#define R_SSI_IDR           (0X0058)
#define R_SSI_COMP_VERSION  (0X005C)
#define R_SSI_DR            (0X0060)
#define R_SSI_RX_SAMPLE_DLY (0X00F0)

/* Bits of SSI_CTRLR0 (0X0000) */

#define DFS_OFFSET 0
#define DFS_BITS   4
#define DFS_MASK   (((1 << 4) - 1) << 0)
#define DFS        (DFS_MASK)

#define FRF_OFFSET 4
#define FRF_BITS   2
#define FRF_MASK   (((1 << 2) - 1) << 4)
#define FRF        (FRF_MASK)

#define SCPH_OFFSET 6
#define SCPH_BITS   1
#define SCPH_MASK   (((1 << 1) - 1) << 6)
#define SCPH        (SCPH_MASK)

#define SCPOL_OFFSET 7
#define SCPOL_BITS   1
#define SCPOL_MASK   (((1 << 1) - 1) << 7)
#define SCPOL        (SCPOL_MASK)

#define TMOD_OFFSET 8
#define TMOD_BITS   2
#define TMOD_MASK   (((1 << 2) - 1) << 8)
#define TMOD        (TMOD_MASK)

#define SLV_OE_OFFSET 10
#define SLV_OE_BITS   1
#define SLV_OE_MASK   (((1 << 1) - 1) << 10)
#define SLV_OE        (SLV_OE_MASK)

#define SRL_OFFSET 11
#define SRL_BITS   1
#define SRL_MASK   (((1 << 1) - 1) << 11)
#define SRL        (SRL_MASK)

#define CFS_OFFSET 12
#define CFS_BITS   4
#define CFS_MASK   (((1 << 4) - 1) << 12)
#define CFS        (CFS_MASK)

#define DFS_32_OFFSET 16
#define DFS_32_BITS   5
#define DFS_32_MASK   (((1 << 5) - 1) << 16)
#define DFS_32        (DFS_32_MASK)

#define SPI_FRF_OFFSET 21
#define SPI_FRF_BITS   2
#define SPI_FRF_MASK   (((1 << 2) - 1) << 21)
#define SPI_FRF        (SPI_FRF_MASK)

#define SSTE_OFFSET 24
#define SSTE_BITS   1
#define SSTE_MASK   (((1 << 1) - 1) << 24)
#define SSTE        (SSTE_MASK)

#define SECONV_OFFSET 25
#define SECONV_BITS   1
#define SECONV_MASK   (((1 << 1) - 1) << 25)
#define SECONV        (SECONV_MASK)

/* Bits of R_SSI_CTRLR1 (0X0004) */

#define NDF_OFFSET 0
#define NDF_BITS   16
#define NDF_MASK   (((1 << 16) - 1) << 0)
#define NDF        (NDF_MASK)

/* Bits of R_SSI_SSIENR (0X0008) */

#define SSI_EN_OFFSET 0
#define SSI_EN_BITS   1
#define SSI_EN_MASK   (((1 << 1) - 1) << 0)
#define SSI_EN        (SSI_EN_MASK)

/* Bits of R_SSI_MWCR (0X000C) */

#define MWMOD_OFFSET 0
#define MWMOD_BITS   1
#define MWMOD_MASK   (((1 << 1) - 1) << 0)
#define MWMOD        (MWMOD_MASK)

#define MDD_OFFSET 1
#define MDD_BITS   1
#define MDD_MASK   (((1 << 1) - 1) << 1)
#define MDD        (MDD_MASK)

#define MHS_OFFSET 2
#define MHS_BITS   1
#define MHS_MASK   (((1 << 1) - 1) << 2)
#define MHS        (MHS_MASK)

/* Bits of R_SSI_SER (0X0010) */

#define SER_OFFSET 0
#define SER_BITS   1
#define SER_MASK   (((1 << 1) - 1) << 0)
#define SER        (SER_MASK)

/* Bits of R_SSI_BAUDR (0X0014) */

#define SCKDV_OFFSET 0
#define SCKDV_BITS   16
#define SCKDV_MASK   (((1 << 16) - 1) << 0)
#define SCKDV        (SCKDV_MASK)

/* Bits of R_SSI_TXFTLR (0X0018) */

#define TFT_OFFSET 0
#define TFT_BITS   3
#define TFT_MASK   (((1 << 3) - 1) << 0)
#define TFT        (TFT_MASK)

/* Bits of R_SSI_RXFTLR (0X001C) */

#define RFT_OFFSET 0
#define RFT_BITS   3
#define RFT_MASK   (((1 << 3) - 1) << 0)
#define RFT        (RFT_MASK)

/* Bits of R_SSI_TXFLR (0X0020) */

#define TXTFL_OFFSET 0
#define TXTFL_BITS   8
#define TXTFL_MASK   (((1 << 8) - 1) << 0)
#define TXTFL        (TXTFL_MASK)

/* Bits of R_SSI_RXFLR (0X0024) */

#define RXTFL_OFFSET 0
#define RXTFL_BITS   8
#define RXTFL_MASK   (((1 << 8) - 1) << 0)
#define RXTFL        (RXTFL_MASK)

/* Bits of R_SSI_SR (0X0028) */

#define BUSY_OFFSET 0
#define BUSY_BITS   1
#define BUSY_MASK   (((1 << 1) - 1) << 0)
#define BUSY        (BUSY_MASK)

#define TFNF_OFFSET 1
#define TFNF_BITS   1
#define TFNF_MASK   (((1 << 1) - 1) << 1)
#define TFNF        (TFNF_MASK)

#define TFE_OFFSET 2
#define TFE_BITS   1
#define TFE_MASK   (((1 << 1) - 1) << 2)
#define TFE        (TFE_MASK)

#define RFNE_OFFSET 3
#define RFNE_BITS   1
#define RFNE_MASK   (((1 << 1) - 1) << 3)
#define RFNE        (RFNE_MASK)

#define RFF_OFFSET 4
#define RFF_BITS   1
#define RFF_MASK   (((1 << 1) - 1) << 4)
#define RFF        (RFF_MASK)

#define TXE_OFFSET 5
#define TXE_BITS   1
#define TXE_MASK   (((1 << 1) - 1) << 5)
#define TXE        (TXE_MASK)

#define DCOL_OFFSET 6
#define DCOL_BITS   1
#define DCOL_MASK   (((1 << 1) - 1) << 6)
#define DCOL        (DCOL_MASK)

/* Bits of R_SSI_IMR (0X002C) */

#define TXEIM_OFFSET 0
#define TXEIM_BITS   1
#define TXEIM_MASK   (((1 << 1) - 1) << 0)
#define TXEIM        (TXEIM_MASK)

#define TXOIM_OFFSET 1
#define TXOIM_BITS   1
#define TXOIM_MASK   (((1 << 1) - 1) << 1)
#define TXOIM        (TXOIM_MASK)

#define RXUIM_OFFSET 2
#define RXUIM_BITS   1
#define RXUIM_MASK   (((1 << 1) - 1) << 2)
#define RXUIM        (RXUIM_MASK)

#define RXOIM_OFFSET 3
#define RXOIM_BITS   1
#define RXOIM_MASK   (((1 << 1) - 1) << 3)
#define RXOIM        (RXOIM_MASK)

#define RXFIM_OFFSET 4
#define RXFIM_BITS   1
#define RXFIM_MASK   (((1 << 1) - 1) << 4)
#define RXFIM        (RXFIM_MASK)

#define MSTIM_OFFSET 5
#define MSTIM_BITS   1
#define MSTIM_MASK   (((1 << 1) - 1) << 5)
#define MSTIM        (MSTIM_MASK)

/* Bits of R_SSI_ISR (0X0030) */

#define TXEIS_OFFSET 0
#define TXEIS_BITS   1
#define TXEIS_MASK   (((1 << 1) - 1) << 0)
#define TXEIS        (TXEIS_MASK)

#define TXOIS_OFFSET 1
#define TXOIS_BITS   1
#define TXOIS_MASK   (((1 << 1) - 1) << 1)
#define TXOIS        (TXOIS_MASK)

#define RXUIS_OFFSET 2
#define RXUIS_BITS   1
#define RXUIS_MASK   (((1 << 1) - 1) << 2)
#define RXUIS        (RXUIS_MASK)

#define RXOIS_OFFSET 3
#define RXOIS_BITS   1
#define RXOIS_MASK   (((1 << 1) - 1) << 3)
#define RXOIS        (RXOIS_MASK)

#define RXFIS_OFFSET 4
#define RXFIS_BITS   1
#define RXFIS_MASK   (((1 << 1) - 1) << 4)
#define RXFIS        (RXFIS_MASK)

#define MSTIS_OFFSET 5
#define MSTIS_BITS   1
#define MSTIS_MASK   (((1 << 1) - 1) << 5)
#define MSTIS        (MSTIS_MASK)

/* Bits of R_SSI_RISR (0X0034) */

#define TXEIR_OFFSET 0
#define TXEIR_BITS   1
#define TXEIR_MASK   (((1 << 1) - 1) << 0)
#define TXEIR        (TXEIR_MASK)

#define TXOIR_OFFSET 1
#define TXOIR_BITS   1
#define TXOIR_MASK   (((1 << 1) - 1) << 1)
#define TXOIR        (TXOIR_MASK)

#define RXUIR_OFFSET 2
#define RXUIR_BITS   1
#define RXUIR_MASK   (((1 << 1) - 1) << 2)
#define RXUIR        (RXUIR_MASK)

#define RXOIR_OFFSET 3
#define RXOIR_BITS   1
#define RXOIR_MASK   (((1 << 1) - 1) << 3)
#define RXOIR        (RXOIR_MASK)

#define RXFIR_OFFSET 4
#define RXFIR_BITS   1
#define RXFIR_MASK   (((1 << 1) - 1) << 4)
#define RXFIR        (RXFIR_MASK)

#define MSTIR_OFFSET 5
#define MSTIR_BITS   1
#define MSTIR_MASK   (((1 << 1) - 1) << 5)
#define MSTIR        (MSTIR_MASK)

/* Bits of R_SSI_TXOICR (0X0038) */

#define TXOICR_OFFSET 0
#define TXOICR_BITS   1
#define TXOICR_MASK   (((1 << 1) - 1) << 0)
#define TXOICR        (TXOICR_MASK)

/* Bits of R_SSI_RXOICR (0X003C) */

#define RXOICR_OFFSET 0
#define RXOICR_BITS   1
#define RXOICR_MASK   (((1 << 1) - 1) << 0)
#define RXOICR        (RXOICR_MASK)

/* Bits of R_SSI_RXUICR (0X0040) */

#define RXUICR_OFFSET 0
#define RXUICR_BITS   1
#define RXUICR_MASK   (((1 << 1) - 1) << 0)
#define RXUICR        (RXUICR_MASK)

/* Bits of R_SSI_MSTICR (0X0044) */

#define MSTICR_OFFSET 0
#define MSTICR_BITS   1
#define MSTICR_MASK   (((1 << 1) - 1) << 0)
#define MSTICR        (MSTICR_MASK)

/* Bits of R_SSI_ICR (0X0048) */

#define ICR_OFFSET 0
#define ICR_BITS   1
#define ICR_MASK   (((1 << 1) - 1) << 0)
#define ICR        (ICR_MASK)

/* Bits of R_SSI_DMACR (0X004C) */

#define RDMAE_OFFSET 0
#define RDMAE_BITS   1
#define RDMAE_MASK   (((1 << 1) - 1) << 0)
#define RDMAE        (RDMAE_MASK)

#define TDMAE_OFFSET 1
#define TDMAE_BITS   1
#define TDMAE_MASK   (((1 << 1) - 1) << 1)
#define TDMAE        (TDMAE_MASK)

/* Bits of R_SSI_DMATDLR (0X0050) */

#define DMATDL_OFFSET 0
#define DMATDL_BITS   8
#define DMATDL_MASK   (((1 << 8) - 1) << 0)
#define DMATDL        (DMATDL_MASK)

/* Bits of R_SSI_DMARDLR (0X0054) */

#define DMARDL_OFFSET 0
#define DMARDL_BITS   8
#define DMARDL_MASK   (((1 << 8) - 1) << 0)
#define DMARDL        (DMARDL_MASK)

/* Bits of R_SSI_IDR (0X0058) */

#define IDCODE_OFFSET 0
#define IDCODE_BITS   32
#define IDCODE_MASK   (((1 << 32) - 1) << 0)
#define IDCODE        (IDCODE_MASK)

/* Bits of R_SSI_COMP_VERSION (0X005C) */

#define SSI_COMP_VERSION_OFFSET 0
#define SSI_COMP_VERSION_BITS   32
#define SSI_COMP_VERSION_MASK   (((1 << 32) - 1) << 0)
#define SSI_COMP_VERSION        (SSI_COMP_VERSION_MASK)

/* Bits of R_SSI_DR (0X0060) */

#define DR_OFFSET 0
#define DR_BITS   16
#define DR_MASK   (((1 << 16) - 1) << 0)
#define DR        (DR_MASK)

/* Bits of R_SSI_RX_SAMPLE_DLY (0X00F0) */

#define RSD_OFFSET 0
#define RSD_BITS   8
#define RSD_MASK   (((1 << 8) - 1) << 0)
#define RSD        (RSD_MASK)

/***********************Definition created by FW**********************/
/* R_SSI_SSIENR */
#define SSI_DIS 0x0

/* R_SSI_CTRLR0 */
#define TMOD_T_AND_R 0x0
#define DFS_8        0x7
#define FRF_MOTO     0x0

#endif /* ZEPHYR_DRIVERS_SPI_SPI_RTS5817_DW_REG_H_ */
