import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def find(u):
    if parent[u] == u: return u
    parent[u] = find(parent[u])
    return parent[u]


def merge(u, v):
    u, v = find(u), find(v)
    if u == v: return
    parent[u] = v


if __name__ == '__main__':
    while True:
        n, m = map(int, input.readline().split())
        if n == 0 and m == 0: break
        pq = []
        total = 0
        ans = 0
        parent = [0] * n
        for i in range(n):
            parent[i] = i

        for _ in range(m):
            here, next, cost = map(int, input.readline().split())
            heappush(pq, (cost, here, next))
            total += cost

        while pq:
            cost, here, next = heappop(pq)
            if find(here) != find(next):
                ans += cost
                merge(here, next)

        print(total - ans)
