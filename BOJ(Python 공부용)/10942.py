import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(2500)


def go(left, right):
    if left >= right: return 1
    if v[left] != v[right]: return 0
    if dp[left][right] != -1: return dp[left][right]
    dp[left][right] = 0
    dp[left][right] = go(left + 1, right - 1)
    return dp[left][right]


if __name__ == '__main__':
    n = int(input.readline())
    v = [int(x) for x in input.readline().split()]
    dp = [[-1] * n for _ in range(n)]
    k = int(input.readline())
    for _ in range(k):
        left, right = map(int, input.readline().split())
        left -= 1
        right -= 1
        print(go(left, right))
