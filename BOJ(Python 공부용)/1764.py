#!/usr/bin/env python

import sys

sys.setrecursionlimit(50000000)

n, m = map(int, sys.stdin.readline().split())
hear = set()
see = set()
for _ in range(n):
    s = sys.stdin.readline().strip("\n")
    hear.add(s)
for _ in range(m):
    s = sys.stdin.readline().strip("\n")
    see.add(s)

ans = list(hear & see)
ans.sort()
print(len(ans))
for i in ans:
    print(i)
