import sys
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(5000)

notprime = [False] * 1000001
cnt = 0
t = sqrt(1000000)
for i in range(2, int(t), 1):
    if notprime[i]: continue
    for j in range(i * i, 1000000, i):
        if notprime[j]: continue
        notprime[j] = True
        cnt += 1

arr = [0] * (1000001 - cnt)
idx = 0
for i in range(2, 1000000, 1):
    if not notprime[i]:
        arr[idx] = i
        idx += 1

a, k = map(int, input.readline().split())
check = False
for i in range(2, k, 1):
    if a % i == 0:
        print("BAD %d" % i)
        check = True
        break

if not check:
    print("GOOD")
