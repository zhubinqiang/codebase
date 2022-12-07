#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import random

def insertion_sort():
    # array = [8, 2, 4, 9, 3, 6]
    array = []
    UINT32upBound=100000
    for i in range(1, 10):
        array.append(random.randint(0,UINT32upBound))


    print(array)

    for j in range(1, len(array)):
        key = array[j]
        i = j - 1
        while key < array[i] and i >= 0:
            array[i+1] = array[i]
            i -= 1
        array[i+1] = key

    print(array)


def main():
    insertion_sort()

if __name__ == '__main__':
    main()

