n = int(input())
board = [[int(x) for x in input()] for y in range(n)]
visited = [[False] * n for _ in range(n)]
arr = []
cnt = 0


def dfs(x, y):
    global cnt
    visited[x][y] = True
    cnt += 1
    for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
        nx = x + dx
        ny = y + dy
        if nx < 0 or nx >= n or ny < 0 or ny >= n or board[nx][ny] == 0 or visited[nx][ny]:
            continue
        dfs(nx, ny)


for i in range(n):
    for j in range(n):
        if board[i][j] == 1 and not visited[i][j]:
            cnt = 0
            dfs(i, j)
            arr.append(cnt)

print(len(arr))
arr.sort()
for i in arr:
    print(i)
