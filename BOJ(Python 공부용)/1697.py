#!/usr/bin/env python

from collections import deque

n, k = map(int, (input().split()))
visited = [False] * 100001


def bfs(st):
    q = deque()
    q.append((st, 0))
    visited[st] = True
    ret = 0
    while q:
        x, dist = q.popleft()
        if x == k:
            ret = dist
            break
        nx = x + 1
        if 0 <= nx <= 100000 and not visited[nx]:
            visited[nx] = True
            q.append((nx, dist + 1))
        nx = x - 1
        if 0 <= nx <= 100000 and not visited[nx]:
            visited[nx] = True
            q.append((nx, dist + 1))
        nx = x * 2
        if 0 <= nx <= 100000 and not visited[nx]:
            visited[nx] = True
            q.append((nx, dist + 1))

    return ret


print(bfs(n))