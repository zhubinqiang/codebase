#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: test.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-05-26 14:10:19
# @last modified: 2021-05-26 14:10:19
# @description:
# ********************************************************

import hello

def f1():
    str = "abcdef"
    print(str)

def f2():
    s = 0
    for i in range(5):
        s += i
    print(f"s = {s}")

def main():
    f1()
    f2()
    hello.f3()

if __name__ == '__main__':
    main()

