import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n, k = map(int, input.readline().split())
    coin = []
    for _ in range(n):
        value = int(input.readline())
        coin.append(value)

    dp = [0] * (k + 1)
    dp[0] = 1

    for i in range(n):
        for j in range(k + 1):
            if j - coin[i] >= 0:
                dp[j] += dp[j - coin[i]]

    print(dp[k])
