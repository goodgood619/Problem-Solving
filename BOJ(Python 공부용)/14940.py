import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def bfs():
    while q:
        x, y, cost = q.popleft()
        for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m or visited[nx][ny] or board[nx][ny] == 0: continue
            visited[nx][ny] = True
            q.append((nx, ny, cost + 1))
            dist[nx][ny] = dist[x][y] + 1


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    q = deque()
    visited = [[False] * m for _ in range(n)]
    dist = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if board[i][j] == 2:
                q.append((i, j, 0))
                visited[i][j] = True

    bfs()
    for i in range(n):
        for j in range(m):
            if board[i][j] == 1 and dist[i][j] == 0:
                print(-1, end=" ")
            elif board[i][j] == 0:
                print(0, end=" ")
            else:
                print(dist[i][j], end=" ")
        print("")
