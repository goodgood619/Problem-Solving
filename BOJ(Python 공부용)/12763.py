import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(15000)


def go(here, graph, t, m):
    if here == n:
        return 0

    if dp[here][t] != -1: return dp[here][t]
    dp[here][t] = 1e9
    for ele in graph[here]:
        next, nexttime, money = ele[0], ele[1], ele[2]
        if t >= nexttime:
            dp[here][t] = min(dp[here][t], go(next, graph, t - nexttime, m) + money)

    return dp[here][t]


if __name__ == '__main__':
    n = int(input.readline())
    t, m = map(int, input.readline().split())
    l = int(input.readline())
    graph = [[] for _ in range(n + 1)]
    dp = [[-1] * (t + 1) for _ in range(n + 1)]
    for _ in range(l):
        here, next, time, money = map(int, input.readline().split())
        graph[here].append((next, time, money))
        graph[next].append((here, time, money))

    res = go(1, graph, t, m)
    if res == 1e9 or res > m:
        print(-1)
    else:
        print(res)
