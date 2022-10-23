#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: python-re.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-06-07 14:53:43
# @last modified: 2022-10-23 16:21:28
# @description:
# ********************************************************
## refer to
## 1. https://zhuanlan.zhihu.com/p/475666454
## 2. https://www.zhihu.com/column/c_1068907378224713728
## 3. https://zhuanlan.zhihu.com/p/127807805

import re

## 只返回第一个匹配项
def f1():
    ## refer to https://zhuanlan.zhihu.com/p/127807805
    ## search 函数值返回第一个
    s = 'a1b23cd456'
    print(re.search('[0-9]+', s).group())

    ## match 从字符开头匹配
    print(re.match('[0-9]+', '123abc', re.DEBUG).group())

    ## fullmatch 整个字符串完全匹配
    print(re.fullmatch('[0-9]+[a-z]+', '123Abc', re.IGNORECASE).group())


## 返回所有匹配
def fall():
    p = re.compile('\d+')
    s = 'a1b23cd456'

    ## 返回一个列表 ['1', '23', '456']
    print(re.findall(p, s))

    ## 返回一个迭代器
    for i in re.finditer(p, s):
        print(i.group())


def search():
    m = re.search('(\w+), (\w+), (\w+)', 'hello, this, is, Python')

    ## ('hello', 'this', 'is')
    print(m.groups())

    ## hello, this, is
    print(m.group())

    ## hello _ this _ is
    print(m.group(1), '_', m.group(2), '_', m.group(3))


## 分割字符串
def split():
    p = re.compile('\d+')
    s = 'a1b23cd456'

    ## ['a', 'b', 'cd', '']
    print(re.split(p, s))

    ## 最多分割几次 ['a', 'b', 'cd456']
    print(re.split(p, s, maxsplit=2))


## 替换
def sub():
    s = 'a1b23cd456ef78'

    ## a b cd ef
    print(re.sub('\d+', ' ', s))

    ## count最大替换次数 a_b_cd456ef78
    print(re.sub('\d+', '_', s, count=2))


    ## 与sub不同的是 返回一个元组 (字符串, 替换次数)
    ## ('a b cd ef ', 4)
    print(re.subn('\d+', ' ', s))



def main():
    # f1()
    # fall()
    # search()
    # split()
    sub()


if __name__ == "__main__":
    main()

