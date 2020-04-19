import sys

sys.setrecursionlimit(100000)

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

sum = 0
idx = int(1e9)


def go(num):
    for i in range(2, num):
        if num % i == 0:
            return 0
    return 1


for i in range(n, m + 1):
    if i == 1: continue
    if go(i):
        sum += i
        idx = min(idx, i)

if sum == 0:
    print(-1)
else:
    print('%d \n%d' % (sum, idx))
