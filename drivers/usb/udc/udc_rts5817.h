/*
 * Copyright (c) 2024 Realtek Semiconductor, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_USB_UDC_RTS5817_H
#define ZEPHYR_DRIVERS_USB_UDC_RTS5817_H

#include <zephyr/device.h>
#include <zephyr/drivers/usb/udc.h>
#include <zephyr/sys/byteorder.h>

/* dlink_usb_reg.h */
#define R_USB2_ANA_CFG0   (0x0000)
#define R_USB2_ANA_CFG1   (0x0004)
#define R_USB2_ANA_CFG2   (0x0008)
#define R_USB2_ANA_CFG3   (0x000C)
#define R_USB2_ANA_CFG4   (0x0010)
#define R_USB2_ANA_CFG5   (0x0014)
#define R_USB2_ANA_CFG6   (0x0018)
#define R_USB2_ANA_CFG7   (0x001C)
#define R_USB2_CTL_CFG0   (0x0020)
#define R_USB2_CTL_CFG1   (0x0024)
#define R_USB2_CTL_CFG2   (0x0028)
#define R_USB2_PHY_CFG0   (0x002C)
#define R_USB2_PHY_CFG1   (0x0030)
#define R_USB2_PHY_CFG2   (0x0034)
#define R_USB2_PHY_STATUS (0x0038)
#define R_USB2_PHY_DUMMY0 (0x003C)
#define R_USB2_PHY_DUMMY1 (0x0040)

#define REG_AUTO_K_OFFSET 16
#define REG_AUTO_K_BITS   1
#define REG_AUTO_K_MASK   (((1 << 1) - 1) << 16)
#define REG_AUTO_K        (REG_AUTO_K_MASK)

#define REG_ADJR_OFFSET 24
#define REG_ADJR_BITS   4
#define REG_ADJR_MASK   (((1 << 4) - 1) << 24)
#define REG_ADJR        (REG_ADJR_MASK)

#define REG_SEN_NORM_OFFSET 0
#define REG_SEN_NORM_BITS   4
#define REG_SEN_NORM_MASK   (((1 << 4) - 1) << 0)
#define REG_SEN_NORM        (REG_SEN_NORM_MASK)

#define REG_SRC_0_OFFSET 26
#define REG_SRC_0_BITS   3
#define REG_SRC_0_MASK   (((1 << 3) - 1) << 26)
#define REG_SRC_0        (REG_SRC_0_MASK)

#define REG_SH_0_OFFSET 8
#define REG_SH_0_BITS   4
#define REG_SH_0_MASK   (((1 << 4) - 1) << 8)
#define REG_SH_0        (REG_SH_0_MASK)

/* u2sie_ep0_reg.h */
#define R_U2SIE_EP0_IRQ_EN      (0x0000)
#define R_U2SIE_EP0_IRQ_STATUS  (0x0008)
#define R_U2SIE_EP0_CFG         (0x000C)
#define R_U2SIE_EP0_CTL0        (0x0010)
#define R_U2SIE_EP0_CTL1        (0x0014)
#define R_U2SIE_EP0_MAXPKT      (0x0018)
#define R_U2SIE_EP0_SETUP_DATA0 (0x001C)
#define R_U2SIE_EP0_SETUP_DATA1 (0x0020)

#define EP0_MAXPKT_OFFSET 0
#define EP0_MAXPKT_BITS   7
#define EP0_MAXPKT_MASK   (((1 << 7) - 1) << 0)
#define EP0_MAXPKT        (EP0_MAXPKT_MASK)

#define EP0_RESET_OFFSET 2
#define EP0_RESET_BITS   1
#define EP0_RESET_MASK   (((1 << 1) - 1) << 2)
#define EP0_RESET        (EP0_RESET_MASK)

#define EP0_NAKOUT_MODE_OFFSET 0
#define EP0_NAKOUT_MODE_BITS   1
#define EP0_NAKOUT_MODE_MASK   (((1 << 1) - 1) << 0)
#define EP0_NAKOUT_MODE        (EP0_NAKOUT_MODE_MASK)

#define I_EP0INTF_OFFSET 0
#define I_EP0INTF_BITS   1
#define I_EP0INTF_MASK   (((1 << 1) - 1) << 0)
#define I_EP0INTF        (I_EP0INTF_MASK)

#define I_EP0OUTTF_OFFSET 1
#define I_EP0OUTTF_BITS   1
#define I_EP0OUTTF_MASK   (((1 << 1) - 1) << 1)
#define I_EP0OUTTF        (I_EP0OUTTF_MASK)

#define I_EP0INF_OFFSET 2
#define I_EP0INF_BITS   1
#define I_EP0INF_MASK   (((1 << 1) - 1) << 2)
#define I_EP0INF        (I_EP0INF_MASK)

#define I_EP0OUTF_OFFSET 3
#define I_EP0OUTF_BITS   1
#define I_EP0OUTF_MASK   (((1 << 1) - 1) << 3)
#define I_EP0OUTF        (I_EP0OUTF_MASK)

#define I_EP0OSHTF_OFFSET 4
#define I_EP0OSHTF_BITS   1
#define I_EP0OSHTF_MASK   (((1 << 1) - 1) << 4)
#define I_EP0OSHTF        (I_EP0OSHTF_MASK)

#define I_EP0CSENDF_OFFSET 5
#define I_EP0CSENDF_BITS   1
#define I_EP0CSENDF_MASK   (((1 << 1) - 1) << 5)
#define I_EP0CSENDF        (I_EP0CSENDF_MASK)

#define I_SETUPF_OFFSET 6
#define I_SETUPF_BITS   1
#define I_SETUPF_MASK   (((1 << 1) - 1) << 6)
#define I_SETUPF        (I_SETUPF_MASK)

#define I_EP0CSF_OFFSET 7
#define I_EP0CSF_BITS   1
#define I_EP0CSF_MASK   (((1 << 1) - 1) << 7)
#define I_EP0CSF        (I_EP0CSF_MASK)

#define EP0_STALL_OFFSET 1
#define EP0_STALL_BITS   1
#define EP0_STALL_MASK   (((1 << 1) - 1) << 1)
#define EP0_STALL        (EP0_STALL_MASK)

#define EP0_CSH_OFFSET 0
#define EP0_CSH_BITS   1
#define EP0_CSH_MASK   (((1 << 1) - 1) << 0)
#define EP0_CSH        (EP0_CSH_MASK)

/* u2mc_ep0_reg.h */
#define R_U2MC_EP0_CTL      (0x0000)
#define R_U2MC_EP0_BC       (0x0004)
#define R_U2MC_EP0_DUMMY    (0x0008)
#define R_U2MC_EP0_BUF_BASE (0x0400)
#define R_U2MC_EP0_BUF_TOP  (0x043F)

#define U_BUF0_EP0_RX_EN_OFFSET 16
#define U_BUF0_EP0_RX_EN_BITS   1
#define U_BUF0_EP0_RX_EN_MASK   (((1 << 1) - 1) << 16)
#define U_BUF0_EP0_RX_EN        (U_BUF0_EP0_RX_EN_MASK)

#define U_BUF0_EP0_TX_EN_OFFSET 0
#define U_BUF0_EP0_TX_EN_BITS   1
#define U_BUF0_EP0_TX_EN_MASK   (((1 << 1) - 1) << 0)
#define U_BUF0_EP0_TX_EN        (U_BUF0_EP0_TX_EN_MASK)

/* u2sie_sys_reg.h */
#define R_U2SIE_SYS_CTRL       (0x0000)
#define R_U2SIE_SYS_ADDR       (0x0004)
#define R_U2SIE_SYS_IRQ_EN     (0x0008)
#define R_U2SIE_SYS_IRQ_STATUS (0x0010)
#define R_U2SIE_SYS_FORCE_CMD  (0x0014)
#define R_U2SIE_SYS_UTMI_CTRL  (0x0018)
#define R_U2SIE_SYS_UTMI_CFG   (0x001C)
#define R_U2SIE_SYS_UTMI_STAT  (0x0020)
#define R_U2SIE_SYS_PHY_CTRL   (0x0024)
#define R_U2SIE_SYS_PHY_N_F    (0x0028)
#define R_U2SIE_SYS_SLBTEST    (0x002C)
#define R_U2SIE_SYS_PKERR_CNT  (0x0030)
#define R_U2SIE_SYS_RXERR_CNT  (0x0034)
#define R_U2SIE_SYS_LPM_CFG0   (0x0038)
#define R_U2SIE_SYS_LPM_DUMMY  (0x003C)
#define R_U2SIE_SYS_SIE_DUMMY0 (0x0040)
#define R_U2SIE_SYS_SIE_DUMMY1 (0x0044)
#define R_U2SIE_SYS_DPHY_CFG   (0x0054)
#define R_U2SIE_SYS_ERROR_IN   (0x0058)

#define CONNECT_EN_OFFSET 0
#define CONNECT_EN_BITS   1
#define CONNECT_EN_MASK   (((1 << 1) - 1) << 0)
#define CONNECT_EN        (CONNECT_EN_MASK)

#define WAKEUP_EN_OFFSET 1
#define WAKEUP_EN_BITS   1
#define WAKEUP_EN_MASK   (((1 << 1) - 1) << 1)
#define WAKEUP_EN        (WAKEUP_EN_MASK)

#define CFG_FORCE_FS_JMP_SPD_NEG_FS_OFFSET 3
#define CFG_FORCE_FS_JMP_SPD_NEG_FS_BITS   1
#define CFG_FORCE_FS_JMP_SPD_NEG_FS_MASK   (((1 << 1) - 1) << 3)
#define CFG_FORCE_FS_JMP_SPD_NEG_FS        (CFG_FORCE_FS_JMP_SPD_NEG_FS_MASK)

#define MODE_HS_OFFSET 4
#define MODE_HS_BITS   1
#define MODE_HS_MASK   (((1 << 1) - 1) << 4)
#define MODE_HS        (MODE_HS_MASK)

#define CFG_FORCE_FW_REMOTE_WAKEUP_OFFSET 6
#define CFG_FORCE_FW_REMOTE_WAKEUP_BITS   1
#define CFG_FORCE_FW_REMOTE_WAKEUP_MASK   (((1 << 1) - 1) << 6)
#define CFG_FORCE_FW_REMOTE_WAKEUP        (CFG_FORCE_FW_REMOTE_WAKEUP_MASK)

#define FORCE_FS_OFFSET 6
#define FORCE_FS_BITS   1
#define FORCE_FS_MASK   (((1 << 1) - 1) << 6)
#define FORCE_FS        (FORCE_FS_MASK)

#define IE_LS_OFFSET 0
#define IE_LS_BITS   1
#define IE_LS_MASK   (((1 << 1) - 1) << 0)
#define IE_LS        (IE_LS_MASK)

#define IE_SOF_OFFSET 1
#define IE_SOF_BITS   1
#define IE_SOF_MASK   (((1 << 1) - 1) << 1)
#define IE_SOF        (IE_SOF_MASK)

#define IE_SUSPND_OFFSET 2
#define IE_SUSPND_BITS   1
#define IE_SUSPND_MASK   (((1 << 1) - 1) << 2)
#define IE_SUSPND        (IE_SUSPND_MASK)

#define IE_RESUME_OFFSET 3
#define IE_RESUME_BITS   1
#define IE_RESUME_MASK   (((1 << 1) - 1) << 3)
#define IE_RESUME        (IE_RESUME_MASK)

#define IE_SE0RST_OFFSET 4
#define IE_SE0RST_BITS   1
#define IE_SE0RST_MASK   (((1 << 1) - 1) << 4)
#define IE_SE0RST        (IE_SE0RST_MASK)

#define IE_L1SLEEP_OFFSET 5
#define IE_L1SLEEP_BITS   1
#define IE_L1SLEEP_MASK   (((1 << 1) - 1) << 5)
#define IE_L1SLEEP        (IE_L1SLEEP_MASK)

#define IE_L1RESUME_OFFSET 6
#define IE_L1RESUME_BITS   1
#define IE_L1RESUME_MASK   (((1 << 1) - 1) << 6)
#define IE_L1RESUME        (IE_L1RESUME_MASK)

#define IE_SOF_INTERVAL_OFFSET 7
#define IE_SOF_INTERVAL_BITS   1
#define IE_SOF_INTERVAL_MASK   (((1 << 1) - 1) << 7)
#define IE_SOF_INTERVAL        (IE_SOF_INTERVAL_MASK)

#define I_LSF_OFFSET 0
#define I_LSF_BITS   1
#define I_LSF_MASK   (((1 << 1) - 1) << 0)
#define I_LSF        (I_LSF_MASK)

#define I_SOFF_OFFSET 1
#define I_SOFF_BITS   1
#define I_SOFF_MASK   (((1 << 1) - 1) << 1)
#define I_SOFF        (I_SOFF_MASK)

#define I_SUSPNDF_OFFSET 2
#define I_SUSPNDF_BITS   1
#define I_SUSPNDF_MASK   (((1 << 1) - 1) << 2)
#define I_SUSPNDF        (I_SUSPNDF_MASK)

#define I_RESUMEF_OFFSET 3
#define I_RESUMEF_BITS   1
#define I_RESUMEF_MASK   (((1 << 1) - 1) << 3)
#define I_RESUMEF        (I_RESUMEF_MASK)

#define I_SE0RSTF_OFFSET 4
#define I_SE0RSTF_BITS   1
#define I_SE0RSTF_MASK   (((1 << 1) - 1) << 4)
#define I_SE0RSTF        (I_SE0RSTF_MASK)

#define I_L1SLEEPF_OFFSET 5
#define I_L1SLEEPF_BITS   1
#define I_L1SLEEPF_MASK   (((1 << 1) - 1) << 5)
#define I_L1SLEEPF        (I_L1SLEEPF_MASK)

#define I_L1RESUMEF_OFFSET 6
#define I_L1RESUMEF_BITS   1
#define I_L1RESUMEF_MASK   (((1 << 1) - 1) << 6)
#define I_L1RESUMEF        (I_L1RESUMEF_MASK)

#define I_SOF_INTERVAL_OFFSET 7
#define I_SOF_INTERVAL_BITS   1
#define I_SOF_INTERVAL_MASK   (((1 << 1) - 1) << 7)
#define I_SOF_INTERVAL        (I_SOF_INTERVAL_MASK)

#define U2SIE_EP_REG_OFFSET 0x100
#define U2MC_EP0_REG_OFFSET 0
#define U2MC_EPA_REG_OFFSET 0x800
#define U2MC_EPB_REG_OFFSET 0x1000
#define U2MC_EPC_REG_OFFSET 0x1800
#define U2MC_EPD_REG_OFFSET 0x1C00
#define U2MC_EPE_REG_OFFSET 0x2000
#define U2MC_EPF_REG_OFFSET 0x2800

#define U2SIE_EP0_REG_OFFSET 0
#define U2SIE_EPA_REG_OFFSET 0x100
#define U2SIE_EPB_REG_OFFSET 0x200
#define U2SIE_EPC_REG_OFFSET 0x300
#define U2SIE_EPD_REG_OFFSET 0x400
#define U2SIE_EPE_REG_OFFSET 0x500
#define U2SIE_EPF_REG_OFFSET 0x600
#define U2SIE_EPG_REG_OFFSET 0x700

/* u2mc_epc_reg.h */
#define R_EPC_U2MC_INTIN_CTL   (0X0000)
#define R_EPC_U2MC_INTIN_BC    (0X0004)
#define R_EPC_U2MC_INTIN_BUF0  (0X0008)
#define R_EPC_U2MC_INTIN_BUF1  (0X000C)
#define R_EPC_U2MC_INTIN_BUF2  (0X0010)
#define R_EPC_U2MC_INTIN_BUF3  (0X0014)
#define R_EPC_U2MC_INTIN_BUF4  (0X0018)
#define R_EPC_U2MC_INTIN_BUF5  (0X001C)
#define R_EPC_U2MC_INTIN_BUF6  (0X0020)
#define R_EPC_U2MC_INTIN_BUF7  (0X0024)
#define R_EPC_U2MC_INTIN_BUF8  (0X0028)
#define R_EPC_U2MC_INTIN_BUF9  (0X002C)
#define R_EPC_U2MC_INTIN_BUF10 (0X0030)
#define R_EPC_U2MC_INTIN_BUF11 (0X0034)
#define R_EPC_U2MC_INTIN_BUF12 (0X0038)
#define R_EPC_U2MC_INTIN_BUF13 (0X003C)
#define R_EPC_U2MC_INTIN_BUF14 (0X0040)
#define R_EPC_U2MC_INTIN_BUF15 (0X0044)
#define R_EPC_U2MC_INTIN_BUF16 (0X0048)
#define R_EPC_U2MC_INTIN_BUF17 (0X004C)
#define R_EPC_U2MC_INTIN_BUF18 (0X0050)
#define R_EPC_U2MC_INTIN_BUF19 (0X0054)
#define R_EPC_U2MC_INTIN_BUF20 (0X0058)
#define R_EPC_U2MC_INTIN_BUF21 (0X005C)
#define R_EPC_U2MC_INTIN_BUF22 (0X0060)
#define R_EPC_U2MC_INTIN_BUF23 (0X0064)
#define R_EPC_U2MC_INTIN_BUF24 (0X0068)
#define R_EPC_U2MC_INTIN_BUF25 (0X006C)
#define R_EPC_U2MC_INTIN_BUF26 (0X0070)
#define R_EPC_U2MC_INTIN_BUF27 (0X0074)
#define R_EPC_U2MC_INTIN_BUF28 (0X0078)
#define R_EPC_U2MC_INTIN_BUF29 (0X007C)
#define R_EPC_U2MC_INTIN_BUF30 (0X0080)
#define R_EPC_U2MC_INTIN_BUF31 (0X0084)

/* u2sie_epg_reg.h */
#define R_EPG_U2SIE_INTOUT_CTL        (0X0000)
#define R_EPG_U2SIE_INTOUT_IRQ_EN     (0X0004)
#define R_EPG_U2SIE_INTOUT_IRQ_STATUS (0X0008)
#define R_EPG_U2SIE_INTOUT_MC         (0X000C)
#define R_EPG_U2SIE_INTOUT_BUF0       (0X0010)
#define R_EPG_U2SIE_INTOUT_BUF1       (0X0014)
#define R_EPG_U2SIE_INTOUT_BUF2       (0X0018)
#define R_EPG_U2SIE_INTOUT_BUF3       (0X001C)
#define R_EPG_U2SIE_INTOUT_BUF4       (0X0020)
#define R_EPG_U2SIE_INTOUT_BUF5       (0X0024)
#define R_EPG_U2SIE_INTOUT_BUF6       (0X0028)
#define R_EPG_U2SIE_INTOUT_BUF7       (0X002C)
#define R_EPG_U2SIE_INTOUT_BUF8       (0X0030)
#define R_EPG_U2SIE_INTOUT_BUF9       (0X0034)
#define R_EPG_U2SIE_INTOUT_BUF10      (0X0038)
#define R_EPG_U2SIE_INTOUT_BUF11      (0X003C)
#define R_EPG_U2SIE_INTOUT_BUF12      (0X0040)
#define R_EPG_U2SIE_INTOUT_BUF13      (0X0044)
#define R_EPG_U2SIE_INTOUT_BUF14      (0X0048)
#define R_EPG_U2SIE_INTOUT_BUF15      (0X004C)
#define R_EPG_U2SIE_INTOUT_BUF16      (0X0050)
#define R_EPG_U2SIE_INTOUT_BUF17      (0X0054)
#define R_EPG_U2SIE_INTOUT_BUF18      (0X0058)
#define R_EPG_U2SIE_INTOUT_BUF19      (0X005C)
#define R_EPG_U2SIE_INTOUT_BUF20      (0X0060)
#define R_EPG_U2SIE_INTOUT_BUF21      (0X0064)
#define R_EPG_U2SIE_INTOUT_BUF22      (0X0068)
#define R_EPG_U2SIE_INTOUT_BUF23      (0X006C)
#define R_EPG_U2SIE_INTOUT_BUF24      (0X0070)
#define R_EPG_U2SIE_INTOUT_BUF25      (0X0074)
#define R_EPG_U2SIE_INTOUT_BUF26      (0X0078)
#define R_EPG_U2SIE_INTOUT_BUF27      (0X007C)
#define R_EPG_U2SIE_INTOUT_BUF28      (0X0080)
#define R_EPG_U2SIE_INTOUT_BUF29      (0X0084)
#define R_EPG_U2SIE_INTOUT_BUF30      (0X0088)
#define R_EPG_U2SIE_INTOUT_BUF31      (0X008C)
#define R_EPG_U2SIE_INTOUT_LEN        (0X0090)

#define EPG_EP_EP_OUT_DATA_DONE_OFFSET 0
#define EPG_EP_EP_OUT_DATA_DONE_BITS   1
#define EPG_EP_EP_OUT_DATA_DONE_MASK   (((1 << 1) - 1) << 0)
#define EPG_EP_EP_OUT_DATA_DONE        (EPG_EP_EP_OUT_DATA_DONE_MASK)

#define EP_DMA_DIR_BULK_OUT 0x00
#define EP_DMA_DIR_BULK_IN  0x01

/* Usb endpoint FIFO depth, only EPA/EPB/EPE/EPF have FIFO */
#define USB_EPA_FIFO_DEPTH 1024
#define USB_EPB_FIFO_DEPTH 1024
#define USB_EPE_FIFO_DEPTH 1024
#define USB_EPF_FIFO_DEPTH 1024

/* Usb endpoint logic number config */
#define USB_EPA_DIR USB_EP_DIR_OUT
#define USB_EPB_DIR USB_EP_DIR_IN
#define USB_EPC_DIR USB_EP_DIR_IN
#define USB_EPD_DIR USB_EP_DIR_IN
#define USB_EPE_DIR USB_EP_DIR_OUT
#define USB_EPF_DIR USB_EP_DIR_IN
#define USB_EPG_DIR USB_EP_DIR_OUT

/* Usb interrupt define */
/* REG_USB_USB_IRQ_EN */
#define USB_LS_LINE_STATE_INT BIT(0)
#define USB_LS_SOF_INT        BIT(1)
#define USB_LS_SUSPEND_INT    BIT(2)
#define USB_LS_RESUME_INT     BIT(3)
#define USB_LS_PORT_RST_INT   BIT(4)
#define USB_LS_L1_SLEEP_INT   BIT(5)
#define USB_LS_L1_RESUME_INT  BIT(6)

#define USB_EP0_INTOKEN_INT           BIT(0)
#define USB_EP0_OUTTOKEN_INT          BIT(1)
#define USB_EP0_DATAPKT_TRANS_INT     BIT(2)
#define USB_EP0_DATAPKT_RECV_INT      BIT(3)
#define USB_EP0_OUT_SHORTPKT_RECV_INT BIT(4)
#define USB_EP0_CTRL_STATUS_END_INT   BIT(5)
#define USB_EP0_SETUP_PACKET_INT      BIT(6)
#define USB_EP0_CTRL_STATUS_INT       BIT(7)

#define USB_EP0_INT_MASK                                                                           \
	(I_EP0INTF | I_EP0OUTTF | I_EP0INF | I_EP0OUTF | I_EP0OSHTF | I_EP0CSENDF | I_SETUPF |     \
	 I_EP0CSF)

#define USB_EPA_INT_MASK (BIT(0) | BIT(1) | BIT(2))
#define USB_EPB_INT_MASK (BIT(0) | BIT(1))
#define USB_EPC_INT_MASK (BIT(0) | BIT(1))
#define USB_EPD_INT_MASK (BIT(0) | BIT(1))
#define USB_EPE_INT_MASK (BIT(0) | BIT(1) | BIT(2))
#define USB_EPF_INT_MASK (BIT(0) | BIT(1))
#define USB_EPG_INT_MASK (BIT(0) | BIT(1))

#define USB_BULKOUT_DATAPKT_RECV_INT  BIT(1)
#define USB_BULKOUT_SHORTPKT_RECV_INT BIT(2)
#define USB_BULKIN_TRANS_END_INT      BIT(1)

#define USB_INTOUT_DATAPKT_RECV_INT BIT(1)
#define USB_INTIN_DATAPKT_TRANS_INT BIT(1)

/* Memory Control */
#define EP_MC_INT_DMA_DONE BIT(0)
#define EP_MC_INT_SIE_DONE BIT(5)

#define USB_EPA_MC_INT_MASK (BIT(0))
#define USB_EPB_MC_INT_MASK (BIT(0) | BIT(5))
#define USB_EPE_MC_INT_MASK (BIT(0))
#define USB_EPF_MC_INT_MASK (BIT(0) | BIT(5))

/* Usb endpoint  define */
#define USB_EP0_MPS        (0x40)
#define USB_BULK_MPS_HS    (0x0200)
#define USB_BULK_MPS_FS    (0x0040)
#define USB_INT_EPG_MPS    (0x80)
#define USB_INT_EPC_MPS_HS (0x80)
#define USB_INT_EPC_MPS_FS (0x40)
#define USB_INT_EPD_MPS    (0x40)

#define USB_EP_DATA_ID_DATA0 0
#define USB_EP_DATA_ID_DATA1 1

#define R_EP_U2SIE_IRQ_EN_OFFSET            0x0004
#define R_EP_U2SIE_IRQ_STATUS_OFFSET        0x000C
#define R_EPG_U2SIE_IRQ_STATUS_OFFSET       0x0008
#define R_EP_U2MC_BULK_FIFO_MODE_OFFSET     0x0014
#define R_EP_U2MC_BULK_FIFO_CTL_OFFSET      0x0008
#define R_EP_U2MC_BULKOUT_FIFO_BC_OFFSET    0x000C
#define R_EP_U2MC_BULKOUT_DMA_CTRL_OFFSET   0x0020
#define R_EP_U2MC_BULKOUT_DMA_LENGTH_OFFSET 0x0024
#define R_EP_U2MC_BULKOUT_DMA_ADDR_OFFSET   0x0028

#define R_EP_U2MC_BULKIN_FIFO_CTL_OFFSET   0x0008
#define R_EP_U2MC_BULKIN_DMA_CTRL_OFFSET   0x0020
#define R_EP_U2MC_BULKIN_DMA_LENGTH_OFFSET 0x0024
#define R_EP_U2MC_BULKIN_DMA_ADDR_OFFSET   0x0028

#define R_EP_U2MC_BULK_IRQ 0X0000
#define R_EP_U2MC_BULK_EN  0X0004

#define R_EP_U2MC_INTIN_BC_OFFSET   0x0004
#define R_EP_U2MC_INTIN_BUF0_OFFSET 0x0008

/* some registers */
#define EP_EN_OFFSET 0
#define EP_EN_BITS   1
#define EP_EN_MASK   (((1 << 1) - 1) << 0)
#define EP_EN        (EP_EN_MASK)

#define EP_STALL_OFFSET 1
#define EP_STALL_BITS   1
#define EP_STALL_MASK   (((1 << 1) - 1) << 1)
#define EP_STALL        (EP_STALL_MASK)

#define EP_RESET_OFFSET 2
#define EP_RESET_BITS   1
#define EP_RESET_MASK   (((1 << 1) - 1) << 2)
#define EP_RESET        (EP_RESET_MASK)

#define EP_FORCE_TOGGLE_OFFSET 3
#define EP_FORCE_TOGGLE_BITS   1
#define EP_FORCE_TOGGLE_MASK   (((1 << 1) - 1) << 3)
#define EP_FORCE_TOGGLE        EP_FORCE_TOGGLE_MASK

#define EP_NAKOUT_MODE_OFFSET 4
#define EP_NAKOUT_MODE_BITS   1
#define EP_NAKOUT_MODE_MASK   (((1 << 1) - 1) << 4)
#define EP_NAKOUT_MODE        (EP_NAKOUT_MODE_MASK)

#define EP_EPNUM_OFFSET 8
#define EP_EPNUM_BITS   4
#define EP_EPNUM_MASK   (((1 << 4) - 1) << 8)
#define EP_EPNUM        (EP_EPNUM_MASK)

#define EP_MAXPKT_OFFSET 16
#define EP_MAXPKT_BITS   10
#define EP_MAXPKT_MASK   (((1 << 10) - 1) << 16)
#define EP_MAXPKT        (EP_MAXPKT_MASK)

/* ep fifo reg */
#define EP_FIFO_FLUSH_OFFSET 0
#define EP_FIFO_FLUSH_BITS   1
#define EP_FIFO_FLUSH_MASK   (((1 << 1) - 1) << 0)
#define EP_FIFO_FLUSH        (EP_FIFO_FLUSH_MASK)

#define EP_FIFO_VALID_OFFSET 1
#define EP_FIFO_VALID_BITS   1
#define EP_FIFO_VALID_MASK   (((1 << 1) - 1) << 1)
#define EP_FIFO_VALID        (EP_FIFO_VALID_MASK)

#define EP_CFG_AUTO_FIFO_VALID_OFFSET 8
#define EP_CFG_AUTO_FIFO_VALID_BITS   1
#define EP_CFG_AUTO_FIFO_VALID_MASK   (((1 << 1) - 1) << 8)
#define EP_CFG_AUTO_FIFO_VALID        (EP_CFG_AUTO_FIFO_VALID_MASK)

#define EP_FIFO_EN_OFFSET 0
#define EP_FIFO_EN_BITS   1
#define EP_FIFO_EN_MASK   (((1 << 1) - 1) << 0)
#define EP_FIFO_EN        (EP_FIFO_EN_MASK)

/* ep2mc bulk out reg */
/* Bits of R_EPA_U2MC_BULKOUT_DMA_CTRL (0X0020) */
#define EP_U_PE_TRANS_EN_OFFSET 0
#define EP_U_PE_TRANS_EN_BITS   1
#define EP_U_PE_TRANS_EN_MASK   (((1 << 1) - 1) << 0)
#define EP_U_PE_TRANS_EN        (EP_U_PE_TRANS_EN_MASK)

#define EP_U_PE_TRANS_DIR_OFFSET 1
#define EP_U_PE_TRANS_DIR_BITS   1
#define EP_U_PE_TRANS_DIR_MASK   (((1 << 1) - 1) << 1)
#define EP_U_PE_TRANS_DIR        (EP_U_PE_TRANS_DIR_MASK)

/* Bits of R_EPA_U2MC_BULKOUT_DMA_LENGTH (0X0024) */

#define EP_U_PE_TRANS_LEN_OFFSET 0
#define EP_U_PE_TRANS_LEN_BITS   16
#define EP_U_PE_TRANS_LEN_MASK   (((1 << 16) - 1) << 0)
#define EP_U_PE_TRANS_LEN        (EP_U_PE_TRANS_LEN_MASK)

/* Bits of R_EPA_U2MC_BULKOUT_DMA_ADDR (0X0028) */

#define EP_U_PE_TRANS_START_ADDR_OFFSET 0
#define EP_U_PE_TRANS_START_ADDR_BITS   32
#define EP_U_PE_TRANS_START_ADDR_MASK   (((1 << 32) - 1) << 0)
#define EP_U_PE_TRANS_START_ADDR        (EP_U_PE_TRANS_START_ADDR_MASK)

/* interrupt ep reg */
/* Bits of R_EPC_U2MC_INTIN_CTL (0X0000) */

#define EP_U_INT_BUF_EN_OFFSET 0
#define EP_U_INT_BUF_EN_BITS   1
#define EP_U_INT_BUF_EN_MASK   (((1 << 1) - 1) << 0)
#define EP_U_INT_BUF_EN        (EP_U_INT_BUF_EN_MASK)

/* Bits of R_EPC_U2MC_INTIN_BC (0X0004) */

#define EP_U_INT_BUF_TX_BC_OFFSET 0
#define EP_U_INT_BUF_TX_BC_BITS   8
#define EP_U_INT_BUF_TX_BC_MASK   (((1 << 8) - 1) << 0)
#define EP_U_INT_BUF_TX_BC        (EP_U_INT_BUF_TX_BC_MASK)

#define rts_clear_int_flag(reg, int_bit) (sys_write32(reg, int_bit))

#endif /* ZEPHYR_DRIVERS_USB_UDC_RTS5817_H */
