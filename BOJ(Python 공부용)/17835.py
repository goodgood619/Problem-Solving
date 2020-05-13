import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def dijk():
    while pq:
        cost, here = heappop(pq)
        if cost > dist[here]: continue
        for value in graph[here]:
            next, nextcost = value[0], value[1]
            if dist[next] > dist[here] + nextcost:
                dist[next] = dist[here] + nextcost
                heappush(pq, (dist[next], next))


if __name__ == '__main__':
    n, m, k = map(int, input.readline().split())
    dist = [int(1e18)] * (n + 1)
    graph = [[] for _ in range(n + 1)]
    pq = []
    for _ in range(m):
        u, v, c = map(int, input.readline().split())
        graph[v].append((u, c))

    already = [int(x) for x in input.readline().split()]
    for here in already:
        dist[here] = 0
        heappush(pq, (0, here))
    dijk()

    Max, idx = 0, 0
    for i in range(1, n + 1):
        if dist[i] != 1e18 and Max < dist[i]:
            Max = dist[i]
            idx = i

    print(idx)
    print(Max)
