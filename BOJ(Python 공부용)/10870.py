#!/usr/bin/env python

def go(n):
    if n==0 : return 0
    if n==1 : return 1
    return go(n-1)+go(n-2)

n = input()
n = int(n)

print("%d" %go(n))