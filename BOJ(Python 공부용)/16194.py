import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def go(k):
    if dp[k] != -1: return dp[k]
    dp[k] = int(1e9)
    for i in range(len(coin)):
        if k - coin[i] >= 0:
            dp[k] = min(dp[k], go(k - coin[i]) + card[i])

    return dp[k]


if __name__ == '__main__':
    n = int(input.readline())
    card = [int(x) for x in input.readline().split()]
    coin = [-1] * n
    dp = [-1] * (n + 1)
    for i in range(n):
        coin[i] = i + 1
    dp[0] = 0
    print(go(n))
