#!/usr/bin/env python

import sys

input = sys.stdin
sys.setrecursionlimit(50000000)

n, m = map(int, input.readline().split())
map1 = {}
map2 = {}
for i in range(1, n + 1):
    s = input.readline().strip("\n")
    map1[i] = s
    map2[s] = i

for i in range(m):
    s = input.readline().strip("\n")
    if '1' <= s[0] <= '9':
        print(map1.get(int(s)))
    else:
        print(map2.get(s))
