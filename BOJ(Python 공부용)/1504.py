import sys
from heapq import heappush, heappop

input = sys.stdin
sys.setrecursionlimit(5000)

n, m = map(int, input.readline().split())
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
    graph[next].append((here, cost))

via1, via2 = map(int, input.readline().split())

ans1 = dijk(1, via1) + dijk(via1, via2) + dijk(via2, n)
ans2 = dijk(1, via2) + dijk(via2, via1) + dijk(via1, n)

ans1 = min(ans1, ans2)
if ans1 >= 2e9:
    print(-1)
else:
    print(ans1)