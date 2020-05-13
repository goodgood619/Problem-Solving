import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def dfs2(x, y, dx, dy, dist, origin):
    nx, ny = x + dx, y + dy
    if nx < 0 or nx >= n or ny < 0 or ny >= m: return
    if board[nx][ny] == 0:
        dfs2(nx, ny, dx, dy, dist + 1, origin)
    elif dist >= 2:
        find = -1
        for i in range(len(v2)):
            for here in v2[i]:
                hx, hy = here[0], here[1]
                if hx == nx and hy == ny:
                    find = i
                    break
            if find != -1:
                break

        if origin != find and find != -1:
            heappush(pq, (dist, origin, find))


def dfs(x, y, v):
    v.append((x, y))
    visited[x][y] = True
    for dx, dy in (-1, 0), (1, 0), (0, 1), (0, -1):
        nx, ny = x + dx, y + dy
        if nx < 0 or nx >= n or ny < 0 or ny >= m or visited[nx][ny] or board[nx][ny] == 0: continue
        dfs(nx, ny, v)


def find(u):
    if u == parent[u]: return u
    parent[u] = find(parent[u])
    return parent[u]


def merge(u, v):
    u, v = find(u), find(v)
    if u == v: return
    parent[u] = v


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    v2 = []
    visited = [[False] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and board[i][j] == 1:
                v = []
                dfs(i, j, v)
                v2.append(v)

    needRoad = len(v2) - 1

    pq = []
    for i in range(len(v2)):
        for x, y in v2[i]:
            for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
                dfs2(x, y, dx, dy, 0, i)

    parent = [0] * len(v2)
    for i in range(len(parent)):
        parent[i] = i

    ans, cnt = 0, 0
    while pq:
        dist, here, next = heappop(pq)
        if find(here) != find(next):
            merge(here, next)
            cnt += 1
            ans += dist

    if ans == 0 or cnt != needRoad:
        print("-1")
    else:
        print(ans)
