import sys
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(100)

notprime = [False] * 1004000
notprime[1] = True
for i in range(2, int(sqrt(1004000))):
    for j in range(i * i, 1004000, i):
        notprime[j] = True
n = int(input.readline())
ok = False
for i in range(n, 1004000, 1):
    if notprime[i]: continue
    s = str(i)
    temp = False
    for j, k in zip(range(0, len(s), 1), range(len(s) - 1, 0, -1)):
        if j > k: break
        if s[j] != s[k]:
            temp = True
            break

    if not temp:
        print(i)
        break
