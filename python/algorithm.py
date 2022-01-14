#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: algorithm.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2022-01-11 13:45:19
# @last modified: 2022-01-11 13:45:19
# @description:
# ********************************************************

import random

def binarySearch(l, item):
    low = 0
    high = len(l) - 1

    while low <= high:
        mid = int( (low + high) / 2 )
        if item < l[mid]:
            high = mid -1
        elif item > l[mid]:
            low = mid + 1
        else:
            return item
    return None

def quickSort(l):
    if len(l) < 2:
        return l
    else:
        pivot = l[0]

        less = [ i for i in l[1:] if i <= pivot ]
        greater = [ i for i in l[1:] if i > pivot ]

        # print(less + [pivot] + greater)
        return quickSort(less) + [pivot] + quickSort(greater)

def get_random_list(n):
    array = []
    # s = set()
    for i in range(n):
        r = random.randint(1, 100)
        array.append(r)
        # s.add(r)
    print(array)
    # print(s)
    # array = list(s)
    return array

def main():
    # l = [2, 4, 5, 1, 3]
    l = get_random_list(10)
    l_sorted = quickSort(l);
    # print(l_sorted)

    l2 = range(1, 10, 2)
    print(binarySearch(l2, 3))

if __name__ == "__main__":
    main()

