import sys

input = sys.stdin
sys.setrecursionlimit(5000)

n, m = map(int, input.readline().split())
cnt = 1
for i in range(n):
    for j in range(m):
        if j == m - 1:
            print(cnt, end="\n")
        else:
            print(cnt, end=" ")
        cnt += 1
