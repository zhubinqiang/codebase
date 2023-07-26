#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: python-basedata.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2023-07-12 14:42:16
# @last modified: 2023-07-12 14:42:16
# @description:
# ********************************************************

def handle_list():
    list_a = [1, 2, 3, 4, 5]
    list_b = ['a', 'b', 'c', 'd', 'e']

    for index, (a, b) in enumerate(zip(list_a, list_b)):
        print(index, a, b)

    # print(f'max: {max(list_a)}')
    # print(f'min: {min(list_a)}')

def handle_dict():
    # d = {'a':1, 'b':2, 'c':3, 'd': 4}
    d = {'d':1, 'c':2, 'b':3, 'a': 4}
    d['x'] = 5

    from collections import OrderedDict
    orderedDict = OrderedDict()
    orderedDict = d

    for key in d:
        print('%s:%s' %(key, d[key]))

    # for key in d.keys():
    #     print(key)

    # for value in d.values():
    #     print(value)

    for key in orderedDict:
        print('%s:%s' %(key, d[key]))

def main():
    # handle_list()
    handle_dict()

if __name__ == '__main__':
    main()

