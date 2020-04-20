#!/usr/bin/env python

from collections import deque

n, m = map(int, input().split())
board = [[int(x) for x in input()] for y in range(n)]
visited = [[False] * m for _ in range(n)]
cnt, area = 0, 0


def bfs(sx, sy):
    q = deque()
    q.append((sx, sy, 1))
    visited[sx][sy] = True
    ret = 1
    while q:
        x, y, dist = q.popleft()
        if x == n - 1 and y == m - 1:
            ret = dist
            break
        for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m or board[nx][ny] == 0:
                continue
            if not visited[nx][ny] and board[nx][ny] == 1:
                q.append((nx, ny, dist + 1))
                visited[nx][ny] = True

    return ret


print(bfs(0, 0))
