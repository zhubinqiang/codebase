#!/usr/bin/env python3
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

def handle_iterator():
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


def handle_yield():
    g = yield_statement()
    print("00000000000")

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
## a_decorator函数是一个装饰器，它接收一个函数作为参数，并返回一个新的函数 wrapper，这个 wrapper函数在调用被装饰的函数前后添加了一些额外的行为。
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

## refer to https://zhuanlan.zhihu.com/p/28010894
class T(object):
    def m1(self, n):
        print('self', self, n)

    @classmethod
    def m2(cls, n):
        print('cls:', cls, n)

    @staticmethod
    def m3(n):
        print(n)

def handle_classmethod():
    t = T()
    t.m1('m1')
    T.m2('m2')
    T.m3('m3')


## closure 闭包。简单理解就是
## 闭包(子函数)是能够读取其他函数(父函数)内部变量的函数
## 下面用闭包实现一个事件监听器
## add_listener 和 trigger_event 是闭包，能读取内部变量 listeners
def event_listener():
    listeners = []

    def add_listener(listener):
        listeners.append(listener)

    def trigger_event(data):
        for listener in listeners:
            listener(data)

    return (add_listener, trigger_event)

def my_listener(data):
    print(f"receive data: {data}")

def handle_closure():
    add_listener, trigger_event = event_listener()
    add_listener(my_listener)
    trigger_event("hello")
    trigger_event("world")


## refer to https://blog.51cto.com/u_16213397/7396986
class Student:
    def __init__(self, name, age, score):
        self.name = name
        self.age = age
        self.score = score

def sorted_objects():
    students = [
            Student('Alice', 18, 90),
            Student('Bob', 20, 80),
            Student('Charlie', 19, 95),
            ]

    sorted_students = sorted(students, key=lambda x: x.score, reverse=True)

    for student in sorted_students:
        print(student.name, student.age, student.score)


class Print:
    def __init__(self, _print):
        self.print(_print)

    @staticmethod
    def print(_print):
        print(_print)

def my_print():
    Print("=====================")

## finally 代码块在任何情况下都会执行
def try_finally():
    try:
        print("try block")
        return "1234"
    except Exception as e:
        raise e
    finally:
        print("finally block")


def main():
    # handle_yield()
    # handle_iterator()
    # test_decorator('Jerry', grades={'Math': 99, 'English': 100, 'Chinese': 100})
    # handle_closure()
    # handle_list()
    # handle_classmethod()
    # sorted_objects()
    # my_print()
    print(try_finally())

if __name__ == '__main__':
    main()


