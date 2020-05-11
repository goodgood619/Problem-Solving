import sys
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(10000)


def go(n, k, bag, dp):
    if k <= 0 or n < 0: return 0
    if dp[n][k] != -1: return dp[n][k]
    dp[n][k] = 0
    dp[n][k] = max(dp[n][k], go(n - 1, k, bag, dp))
    if k - bag[n][0] >= 0:
        dp[n][k] = max(dp[n][k], go(n - 1, k - bag[n][0], bag, dp) + bag[n][1])
    return dp[n][k]


if __name__ == '__main__':
    n, k = map(int, input.readline().split())
    bag = []
    for i in range(n):
        first, second = map(int, input.readline().split())
        bag.append((first, second))

    dp = [[-1] * 100001 for _ in range(n + 1)]
    print(go(n - 1, k, bag, dp))
