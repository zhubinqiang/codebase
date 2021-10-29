#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

BUILD_DIR=${SCRIPT_DIR}/build
INS_DIR=${SCRIPT_DIR}/INS
rm -rf ${BUILD_DIR} ${INS_DIR}

meson build -Dprefix=/usr/local/

ninja -C build

DESTDIR=${PWD}/INS meson install -C build

