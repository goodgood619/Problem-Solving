import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def go(index, t):
    if t == 0: return 1
    if t < 0 or index < 0: return 0
    if dp[index][t] != -1: return dp[index][t]
    dp[index][t] = 0
    for i in range(coin[index][1] + 1):
        if t - i * coin[index][0] >= 0:
            dp[index][t] += go(index - 1, t - i * coin[index][0])

    return dp[index][t]


if __name__ == '__main__':
    t = int(input.readline())
    n = int(input.readline())
    coin = []
    for _ in range(n):
        money, cnt = map(int, input.readline().split())
        coin.append((money, cnt))

    dp = [[-1] * (t + 1) for _ in range(n)]
    print(go(n - 1, t))
