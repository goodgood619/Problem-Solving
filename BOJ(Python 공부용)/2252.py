import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    indegree = [0] * n
    graph = [[] for _ in range(n)]
    q = deque()
    for _ in range(m):
        a, b = map(int, input.readline().split())
        a -= 1
        b -= 1
        indegree[b] += 1
        graph[a].append(b)

    for i in range(n):
        if indegree[i] == 0:
            q.append(i)

    while q:
        here = q.popleft()
        print(here + 1, end=" ")
        for next in graph[here]:
            indegree[next] -= 1
            if indegree[next] == 0:
                q.append(next)
