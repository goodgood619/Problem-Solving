import sys

input = sys.stdin
sys.setrecursionlimit(5000)

n = int(input.readline())
ok = False
for i in range(n):
    p = i
    sum = p
    while p > 0:
        sum += p % 10
        p //= 10

    if sum == n:
        print(i)
        ok = True
        break

if not ok:
    print(0)
