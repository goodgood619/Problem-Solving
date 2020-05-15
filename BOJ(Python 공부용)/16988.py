import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def bfs(i, j, visited2):
    visited2[i][j] = True
    q = deque()
    q.append((i, j))
    check = False
    sum = 1
    while q:
        x, y = q.popleft()
        # 빈칸이있다는거는 잡을수없는 돌을 의미한다
        if board[x][y] == 0: check = True
        for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m or visited2[nx][ny] or board[nx][ny] == 1: continue
            q.append((nx, ny))
            if board[nx][ny] == 2: sum += 1
            visited2[nx][ny] = True

    if check:
        return 0
    else:
        return sum


def dfs(here, cnt, depth):
    global ans
    if cnt == depth:
        visited2 = [[False] * m for _ in range(n)]
        sum = 0
        for i in range(n):
            for j in range(m):
                if board[i][j] == 2 and not visited2[i][j]:
                    ret = bfs(i, j, visited2)
                    sum += ret

        ans = max(ans, sum)
        return
    for i in range(here, len(v)):
        if not visited[i]:
            visited[i] = True
            x, y = v[i][0], v[i][1]
            board[x][y] = 1
            dfs(i + 1, cnt + 1, depth)
            board[x][y] = 0
            visited[i] = False


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    v = []
    ans = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                v.append((i, j))

    visited = [False] * len(v)
    dfs(0, 0, 2)
    print(ans)
