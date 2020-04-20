#!/usr/bin/env python

a = input()
a = int(a)
b = input()
for i in range(len(b)-1,-1,-1):
    c = ord(b[i]) - 48
    print(a*c)

b = int(b)
print(a*b)