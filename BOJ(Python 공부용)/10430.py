#!/usr/bin/env python

a,b,c = map(int,input().split())
print("%d\n%d\n%d\n%d\n" %((a+b)%c,(a%c + b%c)%c,(a*b)%c, (a%c * b%c)%c))
