#!/usr/bin/env python

Max = 0
idx = -1
for i in range(9):
    a = input()
    a = int(a)
    if Max < a :
        Max = a
        idx = i+1

print("%d\n%d\n" %(Max,idx))