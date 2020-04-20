#!/usr/bin/env python

import sys

sys.setrecursionlimit(500000)
cnt = 0
n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)


def dfs(x):
    visited[x] = True
    for Next in graph[x]:
        if not visited[Next]:
            dfs(Next)


for _ in range(m):
    here, next = map(int, sys.stdin.readline().split())
    graph[here].append(next)
    graph[next].append(here)

for i in range(1, n + 1):
    if not visited[i]:
        cnt += 1
        dfs(i)

print(cnt)
