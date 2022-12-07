#!/bin/bash -x
# ********************************************************
# @file: build.sh
# @description:
# refer to https://www.debian.org/doc/manuals/debmake-doc/ch05.zh-cn.html
# sudo apt install -y debmake
# ********************************************************

packagename=hithere
version=1.0

tar czvf ${packagename}_${version}.orig.tar.gz ${packagename}-${version}
cd ${packagename}-${version}

export DEBFULLNAME="bzhux"
export DEBEMAIL="bin.qiangx.zhu@gmail.com"

# Command "sudo", with arguments "-nE" and "--"
export DEB_GAIN_ROOT_CMD='sudo -nE --'
# Command "fakeroot" with the single argument "--"
export DEB_GAIN_ROOT_CMD='fakeroot --'

debmake -x2 \
    --fullname ${DEBFULLNAME} \
    --email ${DEBEMAIL}

    # --copyright \
# dpkg-source --commit
debuild -us -uc


# The current directory is set as: $(CURDIR)=/path/to/package-version/

# Build the source using “debian/rules build” into $(DESTDIR)
#   DESTDIR=debian/binarypackage/ (single binary package)
#   DESTDIR=debian/tmp/ (multi binary package)


## Variables for debian/rules
# under /usr/share/dpkg/*.mk
# architecture.mk buildflags.mk buildtools.mk default.mk pkg-info.mk vendor.mk

## dh
# dh clean : clean files in the source tree.
# dh build : build the source tree
# dh build-arch : build the source tree for architecture dependent packages
# dh build-indep : build the source tree for architecture independent packages
# dh install : install the binary files to $(DESTDIR)
# dh install-arch : install the binary files to $(DESTDIR) for architecture dependent packages
# dh install-indep : install the binary files to $(DESTDIR) for architecture independent packages
# dh binary : generate the deb file
# dh binary-arch : generate the deb file for architecture dependent packages
# dh binary-indep : generate the deb file for architecture independent packages


