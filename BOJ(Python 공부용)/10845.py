#!/usr/bin/env python

import sys
import collections
queue = collections.deque()
n = input()
n = int(n)
for i in range(n):
    choice = sys.stdin.readline().strip()
    if choice[:4] == "push":
        num = int(choice.split(' ')[1])
        queue.append(num)
    if choice[:3] == "pop":
        if not queue:
            print("-1")
            continue
        print("%d" %queue.popleft())
    if choice[:4] == "size":
        print("%d" %len(queue))
    if choice[:5] == "empty":
        if queue:
            print(0)
            continue
        print(1)
    if choice[:5] == "front":
        if queue:
            print("%d" %queue[0])
            continue
        print("-1")    
    if choice[:4] == "back":
        if queue:
            print("%d" %queue[-1])
            continue
        print("-1")
