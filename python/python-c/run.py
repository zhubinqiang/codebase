#!/usr/bin/env python3

# refer to https://blog.csdn.net/qq_35636311/article/details/78255568
import ctypes

so = ctypes.CDLL('sum.so')

def main():
    so.sum(1, 100)

if __name__ == "__main__":
    main()


