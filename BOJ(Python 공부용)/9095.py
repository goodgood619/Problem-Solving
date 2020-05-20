import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    t = int(input.readline())
    dp = [0] * 12
    dp[1], dp[2], dp[3] = 1, 2, 4
    for i in range(4, 12):
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
    for _ in range(t):
        n = int(input.readline())
        print(dp[n])
