import sys
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(2000)


def go(x, y, board, dp):
    if x == n - 1 and y == n - 1: return 1
    if x >= n or y >= n: return 0
    if dp[x][y] != -1: return dp[x][y]
    dp[x][y] = 0
    jump = board[x][y]
    if jump == 0: return 0
    dp[x][y] = go(x + jump, y, board, dp) + go(x, y + jump, board, dp)
    return dp[x][y]


if __name__ == '__main__':
    n = int(input.readline())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    dp = [[-1] * n for _ in range(n)]
    print(go(0, 0, board, dp))
