FROM centos:7.4.1708

ENV TZ "Asia/Shanghai"
ENV no_proxy 127.0.0.1

WORKDIR /root/WS

# COPY utils/CentOS-Base.repo /etc/yum.repos.d/
# COPY utils/epel.repo /etc/yum.repos.d/
# COPY utils/CentOS-SCLo-scl-rh.repo /etc/yum.repos.d/

RUN yum install -y \
	gcc gcc-c++ git \
	which autoconf automake libtool \
	redhat-lsb-core wget openssh-server \

## config ssh
RUN mkdir -p /root/.ssh && \
    chmod 755 /root/.ssh && \
    chmod 600 /root/.ssh/id_rsa && \
    echo 'StrictHostKeyChecking no' >> /etc/ssh/ssh_config && \
    echo 'UserKnownHostsFile /dev/null' >> /etc/ssh/ssh_config


## install cmake
ARG CMAKE_VERSION=3.19.3
RUN wget -c --no-check-certificate https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}.tar.gz && \
    tar xzvf cmake-${CMAKE_VERSION}.tar.gz && \
    cd cmake-${CMAKE_VERSION} && \
    ./bootstrap && \
    make -j$(nproc) && \
    make install && \
    cd /root && rm -rf /root/WS/*


