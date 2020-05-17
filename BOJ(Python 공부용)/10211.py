import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    t = int(input.readline())
    for _ in range(t):
        n = int(input.readline())
        arr = [int(x) for x in input.readline().split()]
        dp = [0] * n
        ans = arr[0]
        for i in range(n):
            if i == 0:
                dp[0] = max(dp[0], arr[0])
                continue
            else:
                dp[i] = max(dp[i - 1], 0) + arr[i]
                ans = max(ans, dp[i])
        print(ans)
