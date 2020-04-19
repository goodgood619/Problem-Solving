import sys

sys.setrecursionlimit(50000000)

n, k = map(int, sys.stdin.readline().split(' '))
a = list(map(int, sys.stdin.readline().split(' ')))
a.sort()
k -= 1
print(a[k])