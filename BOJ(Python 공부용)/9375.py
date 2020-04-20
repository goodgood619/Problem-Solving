#!/usr/bin/env python

import sys

input = sys.stdin
sys.setrecursionlimit(50000000)

t = int(input.readline())
for _ in range(t):
    n = int(input.readline())
    map1 = {}
    for _ in range(n):
        temp = input.readline().strip("\n")
        a, b = temp.split()
        if map1.get(b) is None:
            map1[b] = 1
        else:
            map1[b] += 1

    ans = 1
    for i in map1.keys():
        ans = ans * (map1[i] + 1)

    print(ans - 1)
