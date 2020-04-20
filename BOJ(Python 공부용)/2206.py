#!/usr/bin/env python

import sys
from collections import deque

sys.setrecursionlimit(100000)

n, m = map(int, input().split())

board = [list(sys.stdin.readline()) for _ in range(n)]


def bfs(sx, sy):
    q = deque()
    visited = [[[False] * 2 for _ in range(m)] for _ in range(n)]
    dist = [[[0] * 2 for _ in range(m)] for _ in range(n)]
    visited[sx][sy][0] = True
    dist[sx][sy][0] = 1
    q.append((sx, sy, 0))
    ret = 0
    while q:
        x, y, cost = q.popleft()
        if x == n - 1 and y == m - 1:
            ret = dist[x][y][cost]
            break
        for dx, dy in (-1, 0), (1, 0), (0, 1), (0, -1):
            nx = x + dx
            ny = y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if cost < 1:
                if board[nx][ny] == '0':
                    if not visited[nx][ny][cost]:
                        visited[nx][ny][cost] = True
                        q.append((nx, ny, cost))
                        dist[nx][ny][cost] = dist[x][y][cost] + 1
                else:
                    if not visited[nx][ny][cost + 1]:
                        visited[nx][ny][cost + 1] = True
                        q.append((nx, ny, cost + 1))
                        dist[nx][ny][cost + 1] = dist[x][y][cost] + 1

            else:
                if board[nx][ny] == '1':
                    continue
                if not visited[nx][ny][cost]:
                    visited[nx][ny][cost] = True
                    q.append((nx, ny, cost))
                    dist[nx][ny][cost] = dist[x][y][cost] + 1

    return ret


res = bfs(0, 0)
if res == 0:
    print(-1)
else:
    print(res)
