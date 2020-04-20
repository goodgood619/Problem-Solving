#!/usr/bin/env python

import sys
from collections import deque

sys.setrecursionlimit(100000)

t = int(sys.stdin.readline())


def bfs(sx, sy, ex, ey):
    q = deque()
    visited = [[False] * n for _ in range(n)]
    visited[sx][sy] = True
    q.append((sx, sy, 0))
    ret = 0
    while q:
        x, y, dist = q.popleft()
        if x == ex and y == ey:
            ret = dist
            break
        for dx, dy in (-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1):
            nx = x + dx
            ny = y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny]:
                continue
            visited[nx][ny] = True
            q.append((nx, ny, dist + 1))

    return ret


for _ in range(t):
    n = int(sys.stdin.readline())
    sx, sy = map(int, input().split())
    ex, ey = map(int, input().split())
    print(bfs(sx, sy, ex, ey))
