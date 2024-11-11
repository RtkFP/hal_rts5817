# Copyright (c) 2024 Realtek Semiconductor, Inc.
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(usb)

add_subdirectory_ifdef(CONFIG_CLOCK_CONTROL clock_control)
add_subdirectory_ifdef(CONFIG_FLASH flash)
add_subdirectory_ifdef(CONFIG_GPIO gpio)
add_subdirectory_ifdef(CONFIG_PINCTRL pinctrl)
add_subdirectory_ifdef(CONFIG_REGULATOR regulator)
add_subdirectory_ifdef(CONFIG_RESET reset)
add_subdirectory_ifdef(CONFIG_SPI spi)
add_subdirectory_ifdef(CONFIG_WATCHDOG watchdog)
