import sys
from collections import deque

input = sys.stdin
sys.setrecursionlimit(50000000)

n = int(input.readline())
start, end = map(int, input.readline().split())
m = int(input.readline())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    here, next = map(int, input.readline().split())
    graph[here].append(next)
    graph[next].append(here)


def bfs(start, end):
    q = deque()
    q.append((start, 0))
    visited = [False] * (n + 1)
    visited[start] = True
    ret = -1
    while q:
        here, dist = q.popleft()
        if here == end:
            ret = dist
            break
        for next in graph[here]:
            if not visited[next]:
                visited[next] = True
                q.append((next, dist + 1))

    print(ret)


bfs(start, end)