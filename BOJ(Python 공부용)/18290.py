import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
ans = -1e9


def go(here, cnt, depth):
    global ans
    if cnt == depth:
        sum = 0
        for i in range(len(v)):
            x, y = v[i] // m, v[i] % m
            sum += board[x][y]
            for j in range(i + 1, len(v)):
                x, y, nx, ny = v[i] // m, v[i] % m, v[j] // m, v[j] % m
                if abs(x - nx) + abs(y - ny) <= 1: return
        ans = max(ans, sum)
        return
    for i in range(here, n * m):
        if not visited[i]:
            visited[i] = True
            v.append(i)
            go(i + 1, cnt + 1, depth)
            v.pop()
            visited[i] = False


if __name__ == '__main__':
    n, m, k = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    v = []
    visited = [False] * (n * m)
    go(0, 0, k)
    print(ans)
