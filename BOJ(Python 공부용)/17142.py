import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def bfs(temp):
    visited2 = [[False] * n for _ in range(n)]
    q = deque()
    t = 0
    for i in range(len(temp)):
        x, y = temp[i][0], temp[i][1]
        visited2[x][y] = True
        q.append((x, y, 0))

    while q:
        x, y, cost = q.popleft()
        for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= n or visited2[nx][ny] or board[nx][ny] == 1: continue
            if board[nx][ny] != 2:
                t = max(t, cost + 1)
            q.append((nx, ny, cost + 1))
            visited2[nx][ny] = True

    for i in range(n):
        for j in range(n):
            if board[i][j] == 0 and not visited2[i][j]:
                return int(1e9)

    return t


def dfs(here, cnt, depth):
    global ans
    if cnt == depth:
        ans = min(ans, bfs(temp))
        return
    for i in range(here, len(visited)):
        if not visited[i]:
            visited[i] = True
            temp.append(v[i])
            dfs(i + 1, cnt + 1, depth)
            temp.pop()
            visited[i] = False


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    v, temp = [], []
    ans = int(1e9)
    for i in range(n):
        for j in range(n):
            if board[i][j] == 2:
                v.append((i, j))

    visited = [False] * len(v)
    dfs(0, 0, m)
    if ans == int(1e9):
        print("-1")
    else:
        print(ans)
