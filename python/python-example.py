#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# **********************************************
# @file: python-example.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-04-06 23:28:50
# @last modified: 2021-04-06 23:28:50
# @description:
# **********************************************


## refer to https://blog.csdn.net/mieleizhi0522/article/details/82142856
def yield_statement():
    print("Starting ...")
    while True:
        res = yield 4
        print("res:", res)


def test_yield():
    g = yield_statement()

    ## 4
    print(next(g))
    print("11111111111")

    ## ('res:', None)
    ## 4
    print(next(g))
    print("22222222222")

    ## ('res:', 7)
    ## 4
    print(g.send(7))


def main():
    test_yield()

if __name__ == '__main__':
    main()


