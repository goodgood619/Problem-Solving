import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def bfs():
    q = deque()
    visited = [[False] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if board[i][j] == 1:
                q.append((i, j, 0))
                visited[i][j] = True

    Max = 0
    while q:
        x, y, cost = q.popleft()
        Max = max(Max, cost)
        for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m or visited[nx][ny] or board[nx][ny] == 1 or board[nx][
                ny] == -1: continue
            visited[nx][ny] = True
            q.append((nx, ny, cost + 1))
            board[nx][ny] = 1

    return Max


if __name__ == '__main__':
    m, n = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    zero = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                zero += 1

    if zero == 0:
        print(0)
        sys.exit(0)
    ans = bfs()
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                print("-1")
                sys.exit(0)

    print(ans)
