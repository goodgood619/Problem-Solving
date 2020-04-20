#!/usr/bin/env python
import sys
t = int(input())

sys.setrecursionlimit(100000)


def dfs(x, y):
    visited[x][y] = True
    for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
        nx = x + dx
        ny = y + dy
        if nx < 0 or nx >= m or ny < 0 or ny >= n or visited[nx][ny] or board[nx][ny] == 0:
            continue
        dfs(nx, ny)


for i in range(t):
    m, n, k = map(int, input().split())
    board = [[0] * n for _ in range(m)]
    visited = [[False] * n for _ in range(m)]
    cnt = 0
    for _ in range(k):
        x, y = map(int, input().split())
        board[x][y] = 1

    for a in range(m):
        for b in range(n):
            if not visited[a][b] and board[a][b] == 1:
                dfs(a, b)
                cnt += 1

    print(cnt)
