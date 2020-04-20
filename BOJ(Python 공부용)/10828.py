#!/usr/bin/env python

import sys
import collections
stack = collections.deque()
n = input()
n = int(n)
for i in range(n):
    choice = sys.stdin.readline().strip()
    if choice[:4] == "push":
        num = int(choice.split(' ')[1])
        stack.append(num)
    if choice[:3] == "pop":
        if not stack:
            print("-1")
            continue
        print("%d" %stack.pop())
    if choice[:4] == "size":
        print("%d" %len(stack))
    if choice[:5] == "empty":
        if stack:
            print(0)
            continue
        print(1)
    if choice[:3] == "top":
        if not stack:
            print("-1")
            continue
        print("%d" %stack[-1])

