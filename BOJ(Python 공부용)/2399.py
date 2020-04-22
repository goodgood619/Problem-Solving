import sys

input = sys.stdin
sys.setrecursionlimit(10)

n = int(input.readline())
v = [int(x) for x in input.readline().split()]
v.sort()

sum = 0
for i in range(n):
    for j in range(i, n, 1):
        sum += abs(v[i] - v[j])

print(sum * 2)
