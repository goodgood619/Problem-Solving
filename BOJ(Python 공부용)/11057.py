import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(2000)


def go(here, num):
    if here == n: return 1
    if dp[here][num] != -1: return dp[here][num]
    dp[here][num] = 0
    for i in range(10):
        if num <= i:
            dp[here][num] += go(here + 1, i)

    return dp[here][num]


if __name__ == '__main__':
    n = int(input.readline())
    dp = [[-1] * 10 for _ in range(n + 1)]
    ans = 0
    for i in range(10):
        ans += go(1, i)

    ans %= 10007
    print(ans)
