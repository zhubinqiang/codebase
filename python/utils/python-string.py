#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: python-string.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-06-07 14:53:43
# @last modified: 2023-07-03 16:38:13
# @description:
# ********************************************************

from string import Template

## refer to http://blog.lujun9972.win/blog/2017/03/24/python%E6%A0%BC%E5%BC%8F%E5%8C%96%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E5%87%A0%E7%A7%8D%E6%96%B9%E6%B3%95/index.html


def f1():
    name = "Tom"
    age = 23

    print("my name is %s" %(name))

    print("%s is %d years old" %(name, age))

    # info = {"name": name, "a": 12}
    # print("%(name) is %(a) years old" %(info))

    print("{} is {:f} years old".format(name, age))
    print("{name} is {age} years old".format(name=name, age=age))


def f2():
    name = "Tom"
    age = 23
    salary = 15000.56

    # python version > 3.6
    print(f"{name} is {age} years old")
    print(f"salary is {salary:.1f}")

def f3():
    name = "Tom"
    age = 23

    templ = Template("$name is ${age} years old")
    print(templ.substitute(name=name, age=age))

def main():
    # f1()
    f2()
    # f3()

if __name__ == "__main__":
    main()

