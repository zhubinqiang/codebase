#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: hello.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-05-26 14:21:32
# @last modified: 2021-05-26 14:21:32
# @description:
# ********************************************************

import pdb

def f3():
    s = 0

    ## this is a break point
    pdb.set_trace()
    for i in range(1, 5):
        s += i
    print(f"s = {s}")


