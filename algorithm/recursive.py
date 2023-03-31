#!/usr/bin/env python3
# -*- coding: UTF-8 -*-


# Fibonacci sequence
def f1(n):
    if n == 1 or n == 2:
        return 1
    else:
        return f1(n-1) + f1(n-2)


def f2(n):
    l = [1] * n

    for i in range(2, n):
        l[i] = l[i-1] + l[i-2]

    return l[n-1]


def main():
    num = 16
    result = f1(num)
    result2 = f2(num)
    print(f"Fibonacci({num}) = {result}")
    print(f"Fibonacci({num}) = {result2}")

if __name__ == "__main__":
    main()


