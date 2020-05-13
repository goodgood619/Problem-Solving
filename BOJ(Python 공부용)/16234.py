import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(2000)


def dfs(x, y):
    visited[x][y] = True
    v.append((x, y))
    for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
        nx, ny = x + dx, y + dy
        if nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny] or abs(board[x][y] - board[nx][ny]) < l or abs(
                board[nx][ny] - board[x][y]) > r: continue
        dfs(nx, ny)


if __name__ == '__main__':
    n, l, r = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    ans = 0
    while True:
        visited = [[False] * n for _ in range(n)]
        cnt = 0
        nation = []
        for i in range(n):
            for j in range(n):
                if not visited[i][j]:
                    v = []
                    dfs(i, j)
                    cnt += 1
                    nation.append(v)

        if cnt == n * n: break
        for area in nation:
            sum, cnt = 0, 0
            for region in area:
                x, y = region[0], region[1]
                sum += board[x][y]
                cnt += 1
            sum //= cnt
            for region in area:
                x, y = region[0], region[1]
                board[x][y] = sum

        ans += 1
    print(ans)
