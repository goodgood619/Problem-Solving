import sys

sys.setrecursionlimit(50000000)

n = int(sys.stdin.readline())
v = []
while n > 0:
    v.append(n % 10)
    n //= 10
v.sort(reverse=True)
for i in v:
    print(i, end="")
