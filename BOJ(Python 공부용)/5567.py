import sys
from collections import deque

sys.setrecursionlimit(50000000)


def bfs(here, depth):
    visited[here] = True
    q = deque()
    q.append((here, depth))
    while q:
        here, depth = q.popleft()
        dist[here] = depth
        for e in graph[here]:
            if not visited[e]:
                visited[e] = True
                q.append((e, depth + 1))


n = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)
m = int(sys.stdin.readline())
dist = [0] * (n + 1)
for _ in range(m):
    here, next = map(int, sys.stdin.readline().split())
    graph[here].append(next)
    graph[next].append(here)

bfs(1, 0)
cnt = 0
for i in range(1, n + 1):
    if 1 <= dist[i] <= 2:
        cnt += 1

print(cnt)
