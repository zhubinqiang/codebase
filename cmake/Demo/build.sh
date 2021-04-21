#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

BUILD_DIR=${SCRIPT_DIR}/BUILD

rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

cd ${BUILD_DIR}
cmake ..

make

make package

# make install DESTDIR=${BUILD_DIR}/INSTALL


