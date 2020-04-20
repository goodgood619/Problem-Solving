#!/usr/bin/env python

n = input()
n = int(n)
v = []
for i in range(n):
    v.append(int(input()))

for i in sorted(v):
    print("%d" %(i))
