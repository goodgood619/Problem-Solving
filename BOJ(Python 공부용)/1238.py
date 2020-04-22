import sys
from heapq import heappush, heappop

input = sys.stdin
sys.setrecursionlimit(5000)

n, m, x = map(int, input.readline().split())
graph = [[] for _ in range(n + 1)]


def dijk(start, end):
    dist = [2e9] * (n + 1)
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

    return dist[end]


for _ in range(m):
    here, next, cost = map(int, input.readline().split())
    graph[here].append((next, cost))

v = []
for i in range(1, n + 1):
    if i != x:
        v.append(dijk(i, x) + dijk(x, i))

ans = 0
for i in v:
    ans = max(ans, i)

print(ans)