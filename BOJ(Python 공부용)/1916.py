#!/usr/bin/env python

import sys
from heapq import heappop, heappush

input = sys.stdin
sys.setrecursionlimit(50000000)

n = int(input.readline())
m = int(input.readline())
graph = [[] for _ in range(n + 1)]
dist = [int(1e9)] * (n + 1)


def dijk(start):
    dist[start] = 0
    pq = []
    heappush(pq, (0, start))
    while pq:
        cost, here = heappop(pq)
        if dist[here] < cost:
            continue
        for next, nextcost in graph[here]:
            if dist[next] > dist[here] + nextcost:
                dist[next] = dist[here] + nextcost
                heappush(pq, (dist[next], next))


for _ in range(m):
    here, next, cost = map(int, input.readline().split())
    graph[here].append((next, cost))

start, end = map(int, input.readline().split())
dijk(start)
print(dist[end])