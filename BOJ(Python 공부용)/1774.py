import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(2000)


def find(u):
    if u == parent[u]: return u
    parent[u] = find(parent[u])
    return parent[u]


def merge(u, v):
    u, v = find(u), find(v)
    if u == v: return
    parent[u] = v


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    v = []
    parent = [0] * n
    cnt, ans = 0, 0
    for i in range(n):
        parent[i] = i
    for _ in range(n):
        x, y = map(int, input.readline().split())
        v.append((x, y))

    for _ in range(m):
        a, b = map(int, input.readline().split())
        a -= 1
        b -= 1
        if find(a) != find(b):
            merge(a, b)
            cnt += 1

    pq = []
    for i in range(len(v)):
        for j in range(i + 1, len(v)):
            dist = sqrt((v[i][0] - v[j][0]) * (v[i][0] - v[j][0]) + (v[i][1] - v[j][1]) * (v[i][1] - v[j][1]))
            heappush(pq, (dist, i, j))

    while cnt != n - 1:
        dist, here, next = heappop(pq)
        if find(here) != find(next):
            merge(here, next)
            cnt += 1
            ans += dist

    print("%.2f" % ans)
