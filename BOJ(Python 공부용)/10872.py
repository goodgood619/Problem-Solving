#!/usr/bin/env python

def go(n):
    if n==0 : return 1
    return n*go(n-1)

n = input()
n = int(n)

ans = go(n)
print("%d" %ans)