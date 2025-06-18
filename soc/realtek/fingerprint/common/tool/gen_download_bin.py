#!/usr/bin/env python3
#
# Copyright (c) 2024 Realtek Semiconductor, Inc.
#
# SPDX-License-Identifier: Apache-2.0

import argparse
import hashlib
import pathlib
import subprocess
import sys

PATCH_FLAG = 0x3
PATCH_FLAG_OFFSET = 0x0
PATCH_FLAG_LEN = 0x4
PATCH_IMG_SIZE_OFFSET = 0x4
PATCH_IMG_SIZE_LEN = 0x2

PATCH_CONFIG_LEN = 0x50
PATCH_RESERVED_LEN = 0xF70
PATCH_SHA_LEN = 0x20
PATCH_PADDING_LEN = 0x20

IMG_HEADER_FLAG = 0x2
IMG_HEADER_FLAG_OFFSET = 0x0
IMG_HEADER_FLAG_LEN = 0x4
IMG_HEADER_VER_OFFSET = 0x4
IMG_HEADER_VER_LEN = 0x4
IMG_HEADER_RESERVED_LEN = 0xF8

IMG_SIZE_UNIT = 0x1000
IMG_SHA_LEN = 0x20
IMG_REAR_PADDING_LEN = 0x60


def create_parser(arg_list):
    """create argument parser according to pre-defined arguments

    :param arg_list: when empty, parses command line arguments,
    else parses the given string
    """
    parser = argparse.ArgumentParser(conflict_handler='resolve', allow_abbrev=False)
    parser.add_argument("--input", "-i", nargs='?', dest="input")
    parser.add_argument("--output", "-o", nargs='?', dest="output")
    parser.add_argument("--version", "-v", type=lambda x: int(x, 16), dest="version")

    args = parser.parse_known_args(arg_list.split())

    if arg_list == "":
        args = parser.parse_known_args()

    return args


def file_check(input, output=None):
    """check input and output files
    If the input file is not exists or empty, raise error

    :param input: the input file object
    :param output: the output file object
    """
    if not input.exists():
        raise RuntimeError(f'Input file ({input}) is not exists')
    elif input.stat().st_size == 0:
        raise RuntimeError(f'Input file ({input}) is empty')

    if output is None:
        output = ['out_', input]

    if output.exists():
        if output.samefile(input):
            raise RuntimeError(f'Input file {input} should be different from Output file {output}')
        output.unlink()

    output.touch()
    return output


def gen_rompatch(img_len):
    """generate rom patch for image

    :param img_len: the length of image
    """
    patch_config = bytearray([0x0] * PATCH_CONFIG_LEN)
    patch_config[PATCH_FLAG_OFFSET] = PATCH_FLAG
    patch_config[PATCH_IMG_SIZE_OFFSET] = img_len
    patch_reserved = bytearray([0xFF] * PATCH_RESERVED_LEN)
    patch = patch_config + patch_reserved
    patch_sha = hashlib.sha256(patch).digest()
    patch += patch_sha
    patch_padding = bytearray([0xFF] * PATCH_PADDING_LEN)
    patch += patch_padding
    return patch


def gen_img_header(img_version=0):
    """generate rom patch for image

    :param img_version: the version of image
    """
    img_header = IMG_HEADER_FLAG.to_bytes(IMG_HEADER_FLAG_LEN, "little")
    img_header += img_version.to_bytes(IMG_HEADER_VER_LEN, "little")
    img_header += bytearray([0xFF] * IMG_HEADER_RESERVED_LEN)
    return img_header


def img_padding(img):
    size = len(img) // IMG_SIZE_UNIT
    rear = len(img) % IMG_SIZE_UNIT
    padding_len = 0x0
    if rear <= IMG_SIZE_UNIT - IMG_SHA_LEN - IMG_REAR_PADDING_LEN:
        size += 1
        padding_len = IMG_SIZE_UNIT - rear - IMG_SHA_LEN - IMG_REAR_PADDING_LEN
    else:
        size += 2
        padding_len = 2 * IMG_SIZE_UNIT - rear - IMG_SHA_LEN - IMG_REAR_PADDING_LEN

    img_with_padding = img + bytes([0xFF] * padding_len)
    return size, img_with_padding


def main():
    """main of the application"""

    if len(sys.argv) < 3:
        sys.exit()

    input_file = None
    output_file = None
    fw_version = 0x0

    # parser input arguments
    arguments = create_parser("")
    for arg in vars(arguments[0]):
        if (arg == "input") & (arguments[0].input is not None):
            input_file = arguments[0].input
        elif (arg == "output") & (arguments[0].output is not None):
            output_file = arguments[0].output
        elif (arg == "version") & (arguments[0].version is not None):
            fw_version = arguments[0].version

    # check file
    output_file = file_check(pathlib.Path(input_file), pathlib.Path(output_file))

    # generate image header
    header = gen_img_header(fw_version)

    with open(input_file, 'rb') as origin_img_file:
        # start handling
        origin_img = origin_img_file.read()
        img_with_header = header + origin_img
        img_size, img_with_padding = img_padding(img_with_header)
        img_sha = hashlib.sha256(img_with_padding).digest()
        img_with_sha = img_with_padding + img_sha
        rompatch = gen_rompatch(img_size)
        final_img = rompatch + img_with_sha + bytes([0xFF] * IMG_REAR_PADDING_LEN)
        origin_img_file.close()

    with open(output_file, 'wb') as new_fw:
        new_fw.write(final_img)
        new_fw.close()

    # add dfu suffix
    subprocess.check_call(['dfu-suffix', '-a', output_file])


if __name__ == '__main__':
    main()
