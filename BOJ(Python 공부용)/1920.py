#!/usr/bin/env python

def binary(value,left,right):
    if left > right :
        return 0
    mid = (left+right)/2
    mid = int(mid)
    if v[mid] == value : 
        return 1
    elif v[mid] > value:
        return binary(value,left,mid-1)
    else:
        return binary(value,mid+1,right)

n = int(input())
v = list(map(int,input().split()))
v.sort()
m = int(input())
v2 = list(map(int,input().split()))
for i in v2:
    print(binary(i,0,n-1))