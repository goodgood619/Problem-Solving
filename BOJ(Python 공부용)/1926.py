from collections import deque

n, m = map(int, input().split())
board = [[int(x) for x in input().split()] for y in range(n)]
visited = [[False] * m for _ in range(n)]
cnt, area = 0, 0


def bfs(sx, sy):
    q = deque()
    q.append((sx, sy))
    ret = 1
    visited[i][j] = True
    while q:
        x, y = q.popleft()
        for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if not visited[nx][ny] and board[nx][ny]:
                q.append((nx, ny))
                visited[nx][ny] = True
                ret += 1

    return ret


for i in range(n):
    for j in range(m):
        if not visited[i][j] and board[i][j]:
            area = max(area, bfs(i, j))
            cnt += 1

print(cnt)
print(area)