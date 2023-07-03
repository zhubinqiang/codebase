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
    ## refer to https://www.liaoxuefeng.com/wiki/1016959663602400/1529653965619235
    parser = argparse.ArgumentParser(
            prog="program-name",
            description="How to use argparse",
            epilog="Text at the bottom of help. Copyright(r), 2023")

    ## 位置参数
    parser.add_argument('outfile')

    parser.add_argument('--host', default='localhost')

    ## 此参数必须为int类型:
    parser.add_argument('--port', default='3306', type=int)

    ## 必须的参数
    parser.add_argument('-u', '--user', required=True)
    parser.add_argument('-p', '--password', required=True)
    parser.add_argument('--database', required=True, choices=['testdb', 'testdb2'])

    ## -gz 后面不跟参数值，action='store_true' 这个表示出现-gz 它的值为True
    parser.add_argument('-gz', '--gzcompress', action='store_true', required=False, help='Compress backup files by gz.')

    ## 解析参数
    args = parser.parse_args()

    print(f"outfile = {args.outfile}")
    print(f"host = {args.host}")
    print(f"port = {args.port}")
    print(f"user = {args.user}")
    print(f"password = {args.password}")
    print(f"database = {args.database}")
    print(f"gz = {args.gzcompress}")

    # ./python-argparse.py -u root -p 123456 --database testdb -gz backup.sql


def main():
    f1()


if __name__ == "__main__":
    main()


