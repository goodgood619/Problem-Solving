#!/usr/bin/env python

import sys

sys.setrecursionlimit(50000000)

a = int(sys.stdin.readline())
c = sys.stdin.readline().strip("\n")
b = int(sys.stdin.readline())

if c == '*':
    print(a * b)
else:
    print(a + b)
