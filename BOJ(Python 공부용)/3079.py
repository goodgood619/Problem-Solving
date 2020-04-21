import sys

input = sys.stdin
sys.setrecursionlimit(5000)

n, m = map(int, input.readline().split())
v = []
for _ in range(n):
    num = int(input.readline())
    v.append(num)

left = 0
right = int(1e18)
while left <= right:
    mid = (left + right) // 2
    cnt = 0
    for i in range(len(v)):
        cnt += mid // v[i]

    if cnt < m:
        left = mid + 1
    else:
        right = mid - 1

print(left)