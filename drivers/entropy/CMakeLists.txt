# Copyright (c) 2024 Realtek Semiconductor, Inc.
# SPDX-License-Identifier: Apache-2.0

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_ENTROPY_RTS5817 entropy_rts5817.c)
