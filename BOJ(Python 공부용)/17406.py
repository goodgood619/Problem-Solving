import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def bfs():
    global ans
    newboard = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            newboard[i][j] = board[i][j]
    for x, y, s in temp:
        x -= 1
        y -= 1
        while s > 0:
            first = newboard[x - s][y - s]
            for i in range(x - s, x + s): newboard[i][y - s] = newboard[i + 1][y - s]
            for j in range(y - s, y + s): newboard[x + s][j] = newboard[x + s][j + 1]
            for i in range(x + s, x - s, -1): newboard[i][y + s] = newboard[i - 1][y + s]
            for j in range(y + s, y - s, -1): newboard[x - s][j] = newboard[x - s][j - 1]
            newboard[x - s][y - s + 1] = first
            s -= 1

    for i in range(n):
        sum = 0
        for j in range(m):
            sum += newboard[i][j]
        ans = min(ans, sum)


def dfs(cnt, depth):
    if cnt == depth:
        bfs()
        return
    for i in range(k):
        if not visited[i]:
            visited[i] = True
            temp.append(v[i])
            dfs(cnt + 1, depth)
            temp.pop()
            visited[i] = False


if __name__ == '__main__':
    n, m, k = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    v, temp = [], []
    visited = [False] * k
    for _ in range(k):
        x, y, s = map(int, input.readline().split())
        v.append((x, y, s))
    ans = int(1e9)
    dfs(0, k)
    print(ans)
