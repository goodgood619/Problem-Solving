import sys
from collections import deque

sys.setrecursionlimit(100000)

n, m = map(int, sys.stdin.readline().split())
board = [[int(x) for x in sys.stdin.readline().split()] for y in range(n)]
visited = [False] * (n * m)
v = []
temp = []
ans = 0


def bfs():
    q = deque()
    tempboard = [[0] * m for _ in range(n)]
    tempvisited = [[False] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            tempboard[i][j] = board[i][j]

    for i in range(0, len(temp)):
        sx, sy = divmod(temp[i], m)
        tempboard[sx][sy] = 1

    for i in range(n):
        for j in range(m):
            if tempboard[i][j] == 2:
                q.append((i, j))
                tempvisited[i][j] = True

    while q:
        x, y = q.popleft()
        for dx, dy in (-1, 0), (1, 0), (0, 1), (0, -1):
            nx = x + dx
            ny = y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m or tempvisited[nx][ny] or tempboard[nx][ny] == 1:
                continue
            tempvisited[nx][ny] = True
            tempboard[nx][ny] = 2
            q.append((nx, ny))

    cnt = 0
    for i in range(n):
        for j in range(m):
            if tempboard[i][j] == 0:
                cnt += 1

    return cnt


def dfs(here, cnt, depth):
    global ans
    if cnt == depth:
        ans = max(ans, bfs())
        return
    for i in range(here, len(v)):
        if not visited[i]:
            visited[i] = True
            temp.append(v[i])
            dfs(i + 1, cnt + 1, depth)
            temp.remove(v[i])
            visited[i] = False


for i in range(n):
    for j in range(m):
        if board[i][j] == 0:
            v.append(i * m + j)

dfs(0, 0, 3)
print(ans)