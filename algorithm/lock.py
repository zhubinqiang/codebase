#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: lock.py
# @author: ZhuBinQiang <zhubinqiang@gmail.com>
# @create time: 2024-04-05 00:32:35
# @last modified: 2024-04-05 00:32:35
# @description:
# ********************************************************

import threading
from time import sleep

class SpinLock:
    def __init__(self):
        self.lock = threading.Lock()
        self.flag = False

    def acquire(self):
        while True:
            with self.lock:
                if not self.flag:
                    self.flag = True
                    return
            sleep(0.001)  # 给其他线程运行的机会

    def release(self):
        with self.lock:
            self.flag = False

spinlock = SpinLock()

def thread_func(id):
    spinlock.acquire()
    print(f"Thread {id} entered critical section.")
    sleep(1)  # 模拟耗时操作
    print(f"Thread {id} leaving critical section.")
    spinlock.release()


def handle_spinLock():
	t1 = threading.Thread(target=thread_func, args=(1,))
	t2 = threading.Thread(target=thread_func, args=(2,))

	t1.start()
	t2.start()

	t1.join()
	t2.join()


# 创建一个互斥锁
mutex = threading.Lock()

# 共享资源
counter = 0

def increment():
    global counter
    for _ in range(10000):
        # 尝试获取互斥锁
        mutex.acquire()
        try:
            # 当前线程成功获取到锁，可以安全地访问共享资源
            counter += 1
        finally:
            # 释放互斥锁，使得其他线程可以获取锁来访问共享资源
            mutex.release()

def handle_mutex():
# 创建多个线程
    threads = [threading.Thread(target=increment) for _ in range(5)]

# 启动所有线程
    for t in threads:
        t.start()

# 等待所有线程完成
    for t in threads:
        t.join()

# 打印最终的共享资源值
    print(f"Final counter value: {counter}")




# 创建一个信号量，限制同时访问共享资源的线程数量为2
semaphore = threading.Semaphore(2)

# 共享资源
counter = 0

def increment2():
    global counter
    # 请求信号量
    with semaphore:
        # 当前线程成功获取到信号量，可以安全地访问共享资源
        for _ in range(10000):
            counter += 1

def handle_semaphore():
# 创建多个线程
	threads = [threading.Thread(target=increment2) for _ in range(5)]

# 启动所有线程
	for t in threads:
		t.start()

# 等待所有线程完成
	for t in threads:
		t.join()

# 打印最终的共享资源值
	print(f"Final counter value: {counter}")


def main():
    # handle_spinLock()
    # handle_mutex()
	handle_semaphore()


if __name__ == '__main__':
	main()


