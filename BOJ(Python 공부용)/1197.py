import sys
from heapq import heappush, heappop

input = sys.stdin


def find(u):
    if parent[u] == u: return u
    parent[u] = find(parent[u])
    return parent[u]


def union(u, v):
    u, v = find(u), find(v)
    if u == v: return
    parent[u] = v


if __name__ == '__main__':
    V, E = map(int, input.readline().split())
    graph = [[] for _ in range(V + 1)]
    parent = [0] * (V + 1)
    pq = []
    for i in range(len(parent)):
        parent[i] = i

    for _ in range(E):
        here, next, cost = map(int, input.readline().split())
        heappush(pq, (cost, here, next))

    ans = 0
    while pq:
        cost, here, next = heappop(pq)
        if find(here) != find(next):
            union(here, next)
            ans += cost

    print(ans)