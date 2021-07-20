#!/bin/bash

NAME=mydeb
VERSION=1.4.0-2021.06.04

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
INSTALL_DIR=${SCRIPT_DIR}/${NAME}
DEBIAN_DIR=${INSTALL_DIR}/DEBIAN

rm -rf ${INSTALL_DIR}
mkdir -p ${INSTALL_DIR} ${DEBIAN_DIR}

mkdir -p ${INSTALL_DIR}/usr/bin
cat << "EOF" > ${INSTALL_DIR}/usr/bin/mydeb
ls
pwd
EOF
chmod +x ${INSTALL_DIR}/usr/bin/mydeb

cat << EOF > ${DEBIAN_DIR}/control
Package: ${NAME}
Version: ${VERSION}
Section: devel
Priority: optional
Depends: libc6 (>= 2.17), libgcc1 (>= 1:3.0), libstdc++6 (>= 5.2)
Suggests:
Architecture: amd64
Installed-Size: 4096
Maintainer: $(whoami)
Provides: bioinfoserv-arb
Description: a demo to make a deb package
EOF

echo "/sbin/ldconfig" > ${DEBIAN_DIR}/postinst
echo "/sbin/ldconfig" > ${DEBIAN_DIR}/postrm
chmod +x ${DEBIAN_DIR}/postinst ${DEBIAN_DIR}/postrm

dpkg-deb -b --root-owner-group ${NAME} ${NAME}-${VERSION}-amd64.deb


