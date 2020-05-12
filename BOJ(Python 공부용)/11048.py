import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(10000)


def go(x, y):
    if x == n - 1 and y == m - 1: return board[x][y]
    if dp[x][y] != -1: return dp[x][y]
    dp[x][y] = 0
    for dx, dy in (1, 0), (0, 1), (1, 1):
        nx, ny = x + dx, y + dy
        if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
        dp[x][y] = max(dp[x][y], go(nx, ny) + board[x][y])
    return dp[x][y]


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    dp = [[-1] * m for _ in range(n)]
    print(go(0, 0))
