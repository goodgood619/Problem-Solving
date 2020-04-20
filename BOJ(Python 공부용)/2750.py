#!/usr/bin/env python

n = input()
n = int(n)
v = []
for i in range(n):
    num = input()
    num = int(num)
    v.append(num)

v.sort()

for i in v:
    print("%d" %(i))