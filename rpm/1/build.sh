#!/bin/bash -ex

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SRC_DIR=${SCRIPT_DIR}/src
RPM_DIR=${SCRIPT_DIR}/rpmbuild
SPEC_NAME=mycat.spec

rm -rf ${RPM_DIR}
mkdir -p ${RPM_DIR}/{BUILD,BUILDROOT,RPMS,SOURCES,SPECS,SRPMS}

tar_name=mycat-1
tempdir=$(mktemp -d)/${tar_name}

mkdir -p ${tempdir}

cp ${SRC_DIR}/{*.c,Makefile} ${tempdir}

cd ${tempdir}/..
tar czf ${RPM_DIR}/SOURCES/${tar_name}.tar.gz ${tar_name}
cd ${SCRIPT_DIR}

cp ${SRC_DIR}/00001.patch rpmbuild/SOURCES
cp ${SPEC_NAME} ${RPM_DIR}/SPECS

rpmbuild -ba ${RPM_DIR}/SPECS/${SPEC_NAME} --define "_topdir ${RPM_DIR}"


