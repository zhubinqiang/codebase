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

def f0():
    ## <re.Match object; span=(4, 7), match='163'>
    ## s = 'www.163.com'
    ## s[4:7]
    print(re.search(r'[0-9]+', "www.163.com").group())

    ## match 与search 不同的是它从头开始匹配，并返回匹配的第一个。这个返回值为None
    print(re.match(r'[0-9]+', "www.163.com"))
    print(re.search(r'^[0-9]+', "www.163.com"))

    print(re.match(r'\w+@\w+\.\w+', "example@163.com").group())
    ## fullmatch 字符串从头到尾完全匹配
    print(re.fullmatch(r'\w+@\w+\.\w+', "example@163.com").group())


    ## ['www', '163', 'com']
    print(re.findall(r'\w+', 'www.163.com'))

    ## finditer 返回Match对象的迭代器
    for i in re.finditer(r'\w+', 'www.163.com'):
        print(i.group())


    ## 分组 ()
    ## <re.Match object; span=(0, 15), match='example@163.com'>
    m = re.search(r'(\w+)@(\w+)\.(\w+)', 'example@163.com')

    ## ('example', '163', 'com')
    print(m.groups())
    print(m.group(1), m.group(2), m.group(3))

    ## ('com', '163', 'example')
    print(m.group(3, 2, 1))


    ## \1 引用第一个匹配到的分组
    print(re.search(r'(\w+),\1', 'abc,abc').group())

    ## 'abc.123 123abc'
    print(re.search(r'(\w+)\.(\d+) \2\1', 'abc.123 123abc').group())

    ## 替换
    ### www.163.com
    print(re.sub(r'\s+', '.', 'www  163    com'))

    ### 'www.163    com' 设置最大替换数量
    print(re.sub(r'\s+', '.', 'www  163    com', count=1))

    ### www.163.com
    print(re.sub(r'(\w+)\s(\w+)', r'\2, \1', 'hello world'))



## 只返回第一个匹配项
def f1():
    ## refer to https://zhuanlan.zhihu.com/p/127807805
    ## search 只返回第一个
    s = 'a1b23cd456'
    print(re.search(r'[0-9]+', s).group())

    ## match 从字符开头匹配，只返回第一个
    print(re.match(r'[0-9]+', '123abc', re.DEBUG).group())
    print(re.search(r'^[0-9]+', '123abc', re.DEBUG).group())

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
    f0()
    # f1()
    # fall()
    # search()
    # split()
    # sub()


if __name__ == "__main__":
    main()

