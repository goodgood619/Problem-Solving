#!/usr/bin/env python

import sys

sys.setrecursionlimit(50000000)

n = int(sys.stdin.readline())
v = []
for _ in range(n):
    x, y = map(int, sys.stdin.readline().split())
    v.append((x, y))

v.sort(key=lambda v: (v[1], v[0]))

for i in v:
    print(i[0], i[1])
