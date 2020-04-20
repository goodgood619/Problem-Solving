#!/usr/bin/env python

n = input()
n = int(n)
num = 666
cnt = 1
while True:
    if cnt == n: break
    num+=1
    temp = num
    six = 0
    while temp!=0 :
        sk = temp%10
        if sk== 6: six+=1
        elif six<3 : six =0
        temp/=10
        temp = int(temp)
    if six >=3: cnt+=1

print("%d" %num)