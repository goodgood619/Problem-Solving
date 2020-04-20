#!/usr/bin/env python

t = input()
t = int(t)

for i in range(1,t+1,1):
    a,b = map(int,input().split())
    print("Case #%d: %d" %(i,a+b))