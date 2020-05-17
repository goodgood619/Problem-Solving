import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def dijk(st):
    pq = []
    for i in range(n):
        dist[i] = int(1e9)

    heappush(pq, (0, st))
    dist[st] = 0
    while pq:
        cost, here = heappop(pq)
        if dist[here] < cost: continue
        for j in range(len(graph[here])):
            next, nextcost = graph[here][j][0], graph[here][j][1]
            if check[here][j]: continue
            if dist[next] > dist[here] + nextcost:
                dist[next] = dist[here] + nextcost
                heappush(pq, (dist[next], next))


def dfs(en):
    for e in reverseGraph[en]:
        back, backcost = e[0], e[1]
        if dist[back] + backcost == dist[en]:
            for j in range(len(graph[back])):
                next = graph[back][j][0]
                if next == en:
                    check[back][j] = True
                    dfs(back)


if __name__ == '__main__':
    while True:
        n, m = map(int, input.readline().split())
        if n == 0 and m == 0: break
        st, en = map(int, input.readline().split())
        graph = [[] for _ in range(n)]
        check = [[False] * n for _ in range(n)]
        reverseGraph = [[] for _ in range(n)]
        dist = [0] * n
        for _ in range(m):
            here, next, cost = map(int, input.readline().split())
            graph[here].append((next, cost))
            reverseGraph[next].append((here, cost))

        dijk(st)
        dfs(en)
        dijk(st)
        if dist[en] == int(1e9):
            print("-1")
        else:
            print(dist[en])
