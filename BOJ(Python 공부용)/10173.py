#!/usr/bin/env python

s = [['n','N'],['e','E'],['m','M'],['o','O']]

while True:
    t = input()
    if t == 'EOI':
        break
    cnt = 0
    j = 0
    while j < len(t):
        if t[j] in s[cnt]:
            cnt +=1
            if cnt==4 : 
                print('Found')
                break
        
        else:
            cnt = 0
        j += 1
    else:
            print('Missing')
