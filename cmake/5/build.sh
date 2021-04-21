#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

BUILD_DIR=${SCRIPT_DIR}/BUILD

rm -rf ${BUILD_DIR}
mkdir -p ${BUILD_DIR}

cd ${BUILD_DIR}
cmake ..

# cmake -DUSE_MYMATH=OFF ..

## there is GUI on ccmake
# ccmake ..

make






