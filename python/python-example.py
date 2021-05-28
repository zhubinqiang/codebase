#!/usr/bin/env python
# -*- coding: UTF-8 -*-
# **********************************************
# @file: python-example.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-04-06 23:28:50
# @last modified: 2021-04-06 23:28:50
# @description:
# **********************************************

# refer to https://anandology.com/python-practice-book/iterators.html#the-iteration-protocol
class Iterator(object):

    def __init__(self, start, stop):
        self.current = start
        self.stop =  stop

    def __next__(self):
        if self.current > self.stop:
            raise StopIteration
        else:
            c = self.current
            self.current += 1
        return c

    def __iter__(self):
        return self

def test_iterator():
    x = iter([1, 2, 3])
    print("x1:", next(x))

    count = Iterator(1, 5)
    print("c1:", next(count))

    print("c2 ~ c5: ", end='')
    for i in count:
        print(i, end=',')
    print()


    print("count2: ", end='')
    count2 = Iterator(5, 10)
    while True:
        try:
            print(next(count2), end=',')
        except StopIteration:
            break
    print()


## refer to https://blog.csdn.net/mieleizhi0522/article/details/82142856
def yield_statement():
    print("Starting ...")
    while True:
        res = yield 4
        print("res:", res)


def test_yield():
    g = yield_statement()

    ## 4
    print(next(g))
    print("11111111111")

    ## ('res:', None)
    ## 4
    print(next(g))
    print("22222222222")

    ## ('res:', 7)
    ## 4
    print(g.send(7))


## refer to https://github.com/selfteaching/the-craft-of-selfteaching/blob/master/Part.3.B.3.decorator-iterator-generator.ipynb
## *args 接收并处理所有传递进来的位置参数
## **kwargs 接收并处理所有传递进来的关键字参数。
## args: ('Jerry',), kwargs: {'grades': {'Math': 99, 'English': 100, 'Chinese': 100}}
def a_decorator(func):
    def wrapper(*args, **kwargs):
        print("start a_decorator")
        print(f"calling {func.__name__}, args: {args}, kwargs: {kwargs}")
        return func(*args, **kwargs)
    return wrapper

@a_decorator
def test_decorator(name='Tom', grades={'Math': 100, 'English': 98, 'Chinese': 95}):
    print(f"Name: {name}")
    print(f" Math:{grades['Math']}")
    print(f" English:{grades['English']}")
    print(f" Chinese:{grades['Chinese']}")


def main():
    # test_yield()
    # test_iterator()
    test_decorator('Jerry', grades={'Math': 99, 'English': 100, 'Chinese': 100})

if __name__ == '__main__':
    main()


