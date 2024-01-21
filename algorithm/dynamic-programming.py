#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: dynamic-programming.py
# @author: Zhu, BinQiang <bin.qiangx.zhu@intel.com>
# @create time: 2024-01-20 22:49:59
# @last modified: 2024-01-20 22:49:59
# @description:
# ********************************************************

# refer to https://www.bilibili.com/video/BV1AB4y1w7eT

## 求最长子串的长度

nums = [1, 5, 2, 4, 3]

#################
#
#      1
#  /  /  \  \
#  5  2    4  3
#    / \
#   4   3
#
################

## 返回数组第i个数字开始的最长子序列长度
def L(nums, i):

    ## the last number
    if i == len(nums) - 1:
        return 1

    max_len = 1
    for j in range(i+1, len(nums)):
        if nums[j] > nums[i]:
            max_len = max(max_len, L(nums, j)+1)
    return max_len

def brute_force_enumeration():
    # v = max(L(nums, i) for i in range(len(nums)))

    l = []
    for i in range(len(nums)):
        l.append(L(nums, i))
    v = max(l)
    print(v)


memo = {}

## 返回数组第i个数字开始的最长子序列长度
def L2(nums, i):

    if i in memo:
        return memo[i]

    ## the last number
    if i == len(nums) - 1:
        return 1

    max_len = 1
    for j in range(i+1, len(nums)):
        if nums[j] > nums[i]:
            max_len = max(max_len, L2(nums, j)+1)

    memo[i] = max_len
    return max_len

def dynamic():
    v = max(L2(nums, i) for i in range(len(nums)))
    print(v)


## iterative/Non-recursive implementaion
# [1, 5, 2, 4, 3]
# L(0) = max{ L(1), L(2), L(3), L(4) } + 1
# L(1) = max{ L(2), L(3), L(4) } + 1
# L(2) = max{ L(3), L(4) } + 1
# L(3) = max{ L(4) } + 1
# L(4) = 1

def non_recursive():
    n = len(nums)
    L = [1] * n # initial value: [1, 1, 1, 1, 1]

    for i in reversed(range(n)): # i -> 4, 3, 2, 1, 0
        for j in range(i+1, n):
            if nums[j] > nums[i]:
                L[i] = max(L[i], L[j]+1)

    v = max(L)
    print(v)

if __name__ == '__main__':
    # brute_force_enumeration()
    # dynamic()
    non_recursive()


