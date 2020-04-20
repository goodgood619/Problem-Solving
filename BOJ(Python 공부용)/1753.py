#!/usr/bin/env python

import sys
from heapq import heappush, heappop

sys.setrecursionlimit(50000000)

V, E = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(V + 1)]
st = int(sys.stdin.readline())
dist = [int(1e9)] * (V + 1)


def dijk(st):
    dist[st] = 0
    pq = []
    heappush(pq, (0, st))
    while pq:
        cost, here = heappop(pq)
        if dist[here] < cost:
            continue
        for next, nextcost in graph[here]:
            if dist[next] > dist[here] + nextcost:
                dist[next] = dist[here] + nextcost
                heappush(pq, (dist[next], next))


for _ in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u].append((v, w))

dijk(st)
for i in range(1, V + 1):
    if dist[i] == int(1e9):
        print("INF")
    else:
        print(dist[i])
