#!/usr/bin/env python3

def move(a, b):
    print(f'{a} --> {b}')


#   A     B     C
# source tmp target

# 把第n层从source搬到target上面，借助tmp
def hanoi(n, source, tmp, target):
    if n == 1:
        move(source, target)
        return

    hanoi(n-1, source, target, tmp)
    move(source, target)
    hanoi(n-1, tmp, source, target)

def main():
    hanoi(3, 'A', 'B', 'C')


if __name__ == '__main__':
    main()


