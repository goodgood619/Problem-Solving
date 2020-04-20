#!/usr/bin/env python

from itertools import combinations
n,m = map(int,input().split())
v = list(map(int,input().split()))

Sum = 0 
for i in combinations(v,3):
    s = sum(i)
    if s<= m and Sum<s:
        Sum = s

print(Sum)