import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(1500)


def go(k):
    if dp[k] != -1: return dp[k]
    dp[k] = 0
    for i in range(len(coin) - 1):
        if k - coin[i] >= 0:
            dp[k] = max(dp[k], go(k - coin[i]) + card[i])

    return dp[k]


if __name__ == '__main__':
    n = int(input.readline())
    card = [int(x) for x in input.readline().split()]
    coin = [-1] * (n + 1)
    dp = [-1] * (n + 1)
    dp[0] = 0
    for i in range(len(card)):
        coin[i] = i + 1

    print(go(n))
