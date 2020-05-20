import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def go(n, t):
    if t <= 0 or n < 0: return 0
    if dp[n][t] != -1: return dp[n][t]
    dp[n][t] = 0
    dp[n][t] = max(dp[n][t], go(n - 1, t))
    if t >= score[n][0]: dp[n][t] = max(dp[n][t], go(n - 1, t - score[n][0]) + score[n][1])
    return dp[n][t]


if __name__ == '__main__':
    n, t = map(int, input.readline().split())
    score = []
    dp = [[-1] * (t + 1) for _ in range(n + 1)]
    for i in range(n):
        a, b = map(int, input.readline().split())
        score.append((a, b))

    print(go(n - 1, t))
