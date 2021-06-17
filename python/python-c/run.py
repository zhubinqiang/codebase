#!/usr/bin/env python3

# refer to https://blog.csdn.net/qq_35636311/article/details/78255568
import ctypes
import os

CWD = os.path.abspath(os.path.dirname(__file__))

so = ctypes.CDLL(os.path.join(CWD, 'sum.so'))

def main():
    so.sum(1, 100)

if __name__ == "__main__":
    main()


