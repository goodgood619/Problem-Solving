#!/usr/bin/env python

n = input()
n = int(n)
state = False
for i in range(1,n,1):
    t = i
    i = str(i)
    for a in i:
        t += int(a)
    if t == n :
        state = True
        break
if state:
    print(i)
else: 
    print(0)