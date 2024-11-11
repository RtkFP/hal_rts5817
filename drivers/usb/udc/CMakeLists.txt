# Copyright (c) 2024 Realtek Semiconductor, Inc.
# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_include_directories(${ZEPHYR_BASE}/drivers/usb/udc)
zephyr_library_sources_ifdef(CONFIG_UDC_RTS5817 udc_rts5817.c)
