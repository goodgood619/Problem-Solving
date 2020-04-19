import sys

sys.setrecursionlimit(50000000)

n, k = map(int, sys.stdin.readline().split())
v = []
for i in range(1, n + 1):
    ori, a, b, c = map(int, sys.stdin.readline().split())
    v.append((a, b, c, ori))

v.sort(key=lambda v: (-v[0], -v[1], -v[2]))

rank = 1
temp = 0
index = 0
for i in range(n):
    if v[i][3] == k:
        index = i
        break

for i in range(n):
    if v[index][0:3] == v[i][0:3]:
        print(i + 1)
        break
