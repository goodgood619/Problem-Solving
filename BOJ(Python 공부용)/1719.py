import sys
from heapq import heappush, heappop

input = sys.stdin
sys.setrecursionlimit(5000)

n, m = map(int, input.readline().split())
graph = [[] for _ in range(n + 1)]


def dijk(start, dist, path):
    pq = []
    heappush(pq, (0, start))
    dist[start] = 0
    while pq:
        cost, here = heappop(pq)
        if cost > dist[here]: continue
        for index in graph[here]:
            next = index[0]
            nextcost = index[1]
            if dist[next] > dist[here] + nextcost:
                dist[next] = dist[here] + nextcost
                heappush(pq, (dist[next], next))
                path[next] = here


for _ in range(m):
    here, next, cost = map(int, input.readline().split())
    graph[here].append((next, cost))
    graph[next].append((here, cost))

for i in range(1, n + 1):
    dist = [int(1e9)] * (n + 1)
    path = [0] * (n + 1)
    dijk(i, dist, path)
    for j in range(1, n + 1):
        if i == j:
            print("-", end=" ")
        else:
            check = False
            p = path[j]
            idx = 0
            while p != i:
                idx = p
                p = path[p]
                check = True
            if check:
                print(idx, end=" ")
            else:
                print(j, end=" ")

    print("")
