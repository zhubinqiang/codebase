#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: python-argparse.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-06-07 14:53:43
# @last modified: 2022-09-15 13:56:43
# @description:
# ********************************************************

## refer to https://docs.python.org/zh-cn/3/howto/argparse.html

import argparse


def f1():
    parser = argparse.ArgumentParser()
    parser.parse_args()

def f2():
    parser = argparse.ArgumentParser()
    parser.add_argument("echo")
    args = parser.parse_args()
    print(args.echo)

def f3():
    parser = argparse.ArgumentParser()
    parser.add_argument("echo", help="echo the string you use here")
    parser.add_argument("echo1", help="echo the string you use here2")
    args = parser.parse_args()
    print(args.echo)
    print(args)

def f4():
    parser = argparse.ArgumentParser(description='add a build to berta server')
    parser.add_argument('--path', type=str, required=True, help='Artifactory path')
    parser.add_argument('--product', type=str, required=True, help='berta product')
    parser.add_argument('--jenkins-buildid', type=str, required=True, help='jenkins build id')

    args = parser.parse_args()
    print(args)
    print(args.jenkins_buildid)

def main():
    # f1()
    # f2()
    # f3()
    f4()





if __name__ == "__main__":
    main()

