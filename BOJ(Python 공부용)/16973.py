import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def check(x, y, dx, dy, r, c):
    if dx == 0 and dy == 1:
        nx, ny = x + r * dx, y + c * dy
        if ny >= m: return True
        for _ in range(r):
            if nx >= n or board[nx][ny] == 1: return True
            nx += 1
    elif dx == 1 and dy == 0:
        nx, ny = x + r * dx, y + c * dy
        if nx >= n: return True
        for _ in range(c):
            if ny >= m or board[nx][ny] == 1: return True
            ny += 1
    elif dx == -1 and dy == 0:
        nx, ny = x + dx, y + dy
        if nx < 0: return True
        for _ in range(c):
            if ny >= m or board[nx][ny] == 1: return True
            ny += 1
    else:
        nx, ny = x + dx, y + dy
        if ny < 0: return True
        for _ in range(r):
            if nx >= n or board[nx][ny] == 1: return True
            nx += 1

    return False


def bfs(r, c, sx, sy, ex, ey):
    visited = [[False] * m for _ in range(n)]
    visited[sx][sy] = True
    q = deque()
    q.append((sx, sy, 0))
    while q:
        x, y, cost = q.popleft()
        if x == ex and y == ey: return cost
        for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m or board[nx][ny] == 1 or visited[nx][ny]: continue
            if check(x, y, dx, dy, r, c): continue
            q.append((nx, ny, cost + 1))
            visited[nx][ny] = True

    return -1


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    r, c, sx, sy, ex, ey = map(int, input.readline().split())
    sx -= 1
    sy -= 1
    ex -= 1
    ey -= 1
    print(bfs(r, c, sx, sy, ex, ey))
