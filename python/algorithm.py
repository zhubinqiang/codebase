#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: algorithm.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2022-01-11 13:45:19
# @last modified: 2022-01-11 13:45:19
# @description:
# ********************************************************

import random

def binarySearch(l, item):
    low = 0
    high = len(l) - 1

    while low <= high:
        mid = int( (low + high) / 2 )
        if item < l[mid]:
            high = mid -1
        elif item > l[mid]:
            low = mid + 1
        else:
            return item
    return None

def quickSort(l):
    if len(l) < 2:
        return l
    else:
        pivot = l[0]

        less = [ i for i in l[1:] if i <= pivot ]
        greater = [ i for i in l[1:] if i > pivot ]

        # print(less + [pivot] + greater)
        return quickSort(less) + [pivot] + quickSort(greater)

def get_random_list(n):
    array = []
    # s = set()
    for i in range(n):
        r = random.randint(1, 100)
        array.append(r)
        # s.add(r)
    print(array)
    # print(s)
    # array = list(s)
    return array

def handle_quickSort():
    # l = [2, 4, 5, 1, 3]
    l = get_random_list(10)
    l_sorted = quickSort(l);
    print(l_sorted)

    l2 = range(1, 10, 2)
    print(binarySearch(l2, 3))


# finite-state machine
class StageMachine(object):
    def __init__(self):
        ## 存储状态和对应的转移条件与动作
        self.states = {}
        self.current_state = None

    def add_state(self, state, transition, action, next_state):
        # 状态、转移条件、动作、下一个状态
        if state not in self.states:
            self.states[state] = []
        self.states[state].append((transition, action, next_state))

    def set_initial_state(self, state):
        self.current_state = state

    def process_transition(self, transition):
        if self.current_state is None:
            raise Exception("State machine has not been initialized.")
        for trans, action, next_state in self.states[self.current_state]:
            if trans == transition:
                if action is not None:
                    action()
                self.current_state = next_state
                break
        else:
            raise Exception("Invalid transition.")

def action_a():
    print("Action A")

def action_b():
    print("Action B")

def action_c():
    print("Action C")

def handle_state_machine():
    sm = StageMachine()
    sm.add_state("State 1", "Transition 1", action_a, "State 2")
    sm.add_state("State 2", "Transition 2", action_b, "State 3")
    sm.add_state("State 3", "Transition 3", action_c, "State 1")

    sm.set_initial_state("State 1")

    sm.process_transition("Transition 1")
    sm.process_transition("Transition 2")
    sm.process_transition("Transition 3")
    # sm.process_transition("Invalid Transition")


def main():
    # handle_quickSort()
    handle_state_machine()

if __name__ == "__main__":
    main()

