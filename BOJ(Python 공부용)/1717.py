#!/usr/bin/env python

import sys

def find(u):
    if u == parent[u] : return u
    parent[u] = find(parent[u])
    return parent[u]
def uni(u,v):
    u = find(u)
    v = find(v)
    if u == v : return
    parent[u] = v
n,m = map(int,input().split())
parent = [i for i in range(n+1)]
for i in range(n):
    parent[i] = i
for i in range(m):
    a,b,c = map(int,sys.stdin.readline().split())
    if a == 0 :
        uni(b,c)
    else :
        print("YES") if find(b) == find(c) else print("NO")
