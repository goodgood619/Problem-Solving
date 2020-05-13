import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def check(board):
    for i in range(n):
        for j in range(n):
            if board[i][j] == 9 or board[i][j] == 0: continue
            return False

    return True


def bfs(x, y):
    visited = [[False] * n for _ in range(n)]
    dist = [[0] * n for _ in range(n)]
    visited[x][y] = True

    q = deque()
    possible = []
    q.append((x, y, 0))
    while q:
        x, y, cost = q.popleft()
        for dx, dy in (-1, 0), (1, 0), (0, 1), (0, -1):
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny] or board[nx][ny] > level: continue
            q.append((nx, ny, cost + 1))
            visited[nx][ny] = True
            dist[nx][ny] = dist[x][y] + 1

    for i in range(n):
        for j in range(n):
            if dist[i][j] > 0 and 0 < board[i][j] < level:
                possible.append((dist[i][j], i, j))

    if len(possible) >= 1:
        possible.sort()
        return possible[0]
    else:
        return 0, 0, 0


if __name__ == '__main__':
    n = int(input.readline())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    x, y, level, eat, time = 0, 0, 2, 0, 0
    for i in range(n):
        for j in range(n):
            if board[i][j] == 9:
                x, y = i, j

    while True:
        if check(board): break
        v = []
        ret = bfs(x, y)
        if ret[0] == 0 and ret[1] == 0 and ret[2] == 0: break
        t, ex, ey = ret[0], ret[1], ret[2]
        eat += 1
        if level == eat:
            eat = 0
            level += 1
        board[ex][ey] = 9
        board[x][y] = 0
        x, y = ex, ey
        time += t

    print(time)
