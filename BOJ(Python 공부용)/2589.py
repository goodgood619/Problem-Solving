#!/usr/bin/env python

import sys
from collections import deque

input = sys.stdin
sys.setrecursionlimit(50000000)


def bfs(x, y):
    q = deque()
    q.append((x, y, 0))
    visited = [[False] * m for _ in range(n)]
    visited[x][y] = True
    sum = 0
    while q:
        x, y, dist = q.popleft()
        sum = max(sum, dist)
        for dx, dy in (-1, 0), (1, 0), (0, 1), (0, -1):
            nx = x + dx
            ny = y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m or board[nx][ny] == 'W' or visited[nx][ny]: continue
            visited[nx][ny] = True
            q.append((nx, ny, dist + 1))

    return sum


n, m = map(int, input.readline().split())
board = [list(input.readline().strip()) for _ in range(n)]

Max = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 'L':
            Max = max(Max, bfs(i, j))

print(Max)
