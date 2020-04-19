import sys

input = sys.stdin
sys.setrecursionlimit(50000000)

n = int(input.readline())
board = [[int(x) for x in input.readline().split()] for _ in range(n)]
minHeight = int(1e9)
maxHeight = 1


def dfs(x, y):
    visited[x][y] = True
    for dx, dy in (-1, 0), (1, 0), (0, 1), (0, -1):
        nx = x + dx
        ny = y + dy
        if nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny]: continue
        dfs(nx, ny)


for i in range(n):
    for j in range(n):
        minHeight = min(minHeight, board[i][j])
        maxHeight = max(maxHeight, board[i][j])

if minHeight == maxHeight:
    print("1")
else:
    ans = 0
    for i in range(minHeight, maxHeight + 1):
        visited = [[False] * n for _ in range(n)]
        for j in range(n):
            for k in range(n):
                if board[j][k] <= i:
                    visited[j][k] = True

        cnt = 0
        for j in range(n):
            for k in range(n):
                if not visited[j][k]:
                    dfs(j, k)
                    cnt += 1

        ans = max(ans, cnt)

    print(ans)
