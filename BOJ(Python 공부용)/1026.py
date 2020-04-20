#!/usr/bin/env python

import sys

sys.setrecursionlimit(50000000)

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split(' ')))
b = list(map(int, sys.stdin.readline().split(' ')))

a.sort()
b.sort()
sum = 0
j = len(b) - 1
for i in range(0, len(a)):
    sum += a[i] * b[j]
    j -= 1

print(sum)
