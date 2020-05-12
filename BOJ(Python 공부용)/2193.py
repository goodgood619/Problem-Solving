import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def go(here, num):
    if here == n: return 1
    if dp[here][num] != -1: return dp[here][num]
    dp[here][num] = 0
    if num == 0:
        dp[here][num] += go(here + 1, 1)
        dp[here][num] += go(here + 1, 0)
    else:
        dp[here][num] += go(here + 1, 0)
    return dp[here][num]


if __name__ == '__main__':
    n = int(input.readline())
    dp = [[-1] * 2 for _ in range(n + 1)]
    print(go(1, 1))
