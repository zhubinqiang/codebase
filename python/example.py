#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: example.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-04-06 11:19:13
# @last modified: 2021-04-06 11:19:13
# @description:
# ********************************************************

import os
import requests

def download():
    url = 'https://example.com/data.tar.gz'
    user = 'admin'
    passwd = 'admin'

    ## https://docs.python-requests.org/zh_CN/latest/api.html#requests.Response.iter_content
    r = requests.get(url, stream=True, auth=(user, passwd))
    if r.ok:
        print("r.ok:%s" %(r.ok))
        b = True
        with open(os.path.basename(url), 'wb') as f:
            for i in r.iter_content(chunk_size=1024):
                f.write(i)

    session = requests.Session()
    r2 = session.get(url, stream=True, auth=(user, passwd))


if __name__ == '__main__':
    download()

