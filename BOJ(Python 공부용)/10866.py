#!/usr/bin/env python

import sys
import collections
deque = collections.deque()
n = input()
n = int(n)
for i in range(n):
    choice = sys.stdin.readline().strip()
    if choice[:10] == "push_front":
        num = int(choice[11:])
        deque.appendleft(num)
    if choice[:9] == "push_back" :
        num = int(choice[10:])
        deque.append(num)
    if choice[:9] == "pop_front" :
        if not deque:
            print("-1")
            continue
        print("%d" %deque.popleft())
    if choice[:8] == "pop_back":
        if not deque:
            print("-1")
            continue
        print("%d" %deque.pop())
    if choice[:4] == "size":
        print("%d" %len(deque))
    if choice[:5] == "empty":
        if deque:
            print("0")
            continue
        print("1")
    if choice[:5] == "front":
        if not deque:
            print("-1")
            continue
        print("%d" %deque[0])
    if choice[:4] == "back":
        if not deque:
            print("-1")
            continue
        print("%d" %deque[-1])