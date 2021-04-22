#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

BUILD_DIR=${SCRIPT_DIR}/BUILD

rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

cd ${BUILD_DIR}
cmake -DCMAKE_INSTALL_PREFIX=/usr ..

# cmake ..

make

# make install DESTDIR=${BUILD_DIR}/INSTALL

cpack -C CPackConfig.cmake

cpack -C CPackSourceConfig.cmake


