#!/bin/bash -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
RPM_DIR=${SCRIPT_DIR}/rpmbuild

ins_dir="$1"

if [[ ! -e ${ins_dir} ]]; then
    echo "not found directory"
    exit 128
fi

rm -rf ${RPM_DIR}
mkdir -p ${RPM_DIR}/{BUILD,BUILDROOT,RPMS,SOURCES,SPECS,SRPMS}

name="hello-world"
version=1
release=1

spec=${RPM_DIR}/SPECS/${name}.spec

cat << EOF > ${spec}
Name:       ${name}
Version:    ${version}
Release:    ${release}
Summary:    Most simple RPM package

License:    MIT
URL:        https://rpm-packaging-guide.github.io
Source0:    %{name}-%{version}.tar.gz

%description
This is my first RPM package, which does nothing.

%prep
%setup -q

%build
# let's skip this for now

%install
mkdir -p %{buildroot}/usr/
#install -m 755 hello-world.sh %{buildroot}/usr/bin/hello-world.sh
cp -a ./* %{buildroot}/

%changelog
# let's skip this for now
EOF

files=$( cd ${ins_dir}; find . -type f -print0 | xargs -0 -n1 |  cut -c 2-)
cat << EOF >> ${spec}
%files
${files}
EOF

mkdir -p ${RPM_DIR}/SOURCES/${name}-${version}
cp -a ${ins_dir}/* ${RPM_DIR}/SOURCES/${name}-${version}
cd ${RPM_DIR}/SOURCES/
tar czf ${name}-${version}.tar.gz ${name}-${version} --remove-files
cd ${SCRIPT_DIR}


rpmbuild -ba ${spec} --define "_topdir ${RPM_DIR}"

