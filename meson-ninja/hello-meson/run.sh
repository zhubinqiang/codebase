#!/bin/bash

rm -rf build
meson build -Dprefix=/usr/local/
ninja -C build
DESTDIR=$PWD/INS meson install -C build
meson test -C build

