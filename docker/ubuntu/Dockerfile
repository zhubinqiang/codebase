FROM ubuntu:20.04

ENV TZ "Asia/Shanghai"

WORKDIR /root/WS

# COPY utils/sources.list /etc/apt/sources.list
# COPY utils/apt.conf /etc/apt/apt.conf

RUN apt update && \
	DEBIAN_FRONTEND="noninteractive" \
	apt install --no-install-recommends -y \
	git ssh vim gcc g++ make cmake wget lsb-release \
	pkg-config autoconf libtool automake \
	bc bison flex rsync build-essential dpkg-dev \
	kmod cpio patch  \
	python3-pip python3-setuptools python3-dev \

## config ssh
RUN mkdir -p /root/.ssh && \
    chmod 755 /root/.ssh && \
    chmod 600 /root/.ssh/id_rsa && \
    echo 'StrictHostKeyChecking no' >> /etc/ssh/ssh_config && \
    echo 'UserKnownHostsFile /dev/null' >> /etc/ssh/ssh_config


