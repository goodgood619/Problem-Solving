#!/usr/bin/env python

import sys

sys.setrecursionlimit(50000000)


def go(n, m):
    if n < m: return 0
    if m == 0 or n == m:
        return 1
    if dp[n][m] != -1:
        return dp[n][m]
    dp[n][m] = 0
    dp[n][m] = go(n - 1, m) + go(n - 1, m - 1)
    return dp[n][m]


n, m = map(int, sys.stdin.readline().split())
dp = [[-1] * (m + 1) for _ in range(n + 1)]

print(go(n, m))