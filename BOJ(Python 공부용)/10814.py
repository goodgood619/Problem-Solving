#!/usr/bin/env python

import sys

sys.setrecursionlimit(50000000)

n = int(sys.stdin.readline())
v = []
for i in range(n):
    temp = sys.stdin.readline().split()
    temp[0] = int(temp[0])
    temp.append(i)
    v.append(temp)

v = sorted(v, key=lambda x: (x[0], x[2]))

for i in v:
    print(i[0], i[1])
