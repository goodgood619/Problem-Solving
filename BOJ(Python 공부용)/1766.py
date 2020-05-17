import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    pq = []
    graph = [[] for _ in range(n)]
    indegree = [0] * n
    for _ in range(m):
        first, next = map(int, input.readline().split())
        first -= 1
        next -= 1
        graph[first].append(next)
        indegree[next] += 1

    for i in range(n):
        if indegree[i] == 0:
            heappush(pq, i)
    while pq:
        here = heappop(pq)
        print(here + 1, end=" ")
        for next in graph[here]:
            indegree[next] -= 1
            if indegree[next] == 0:
                heappush(pq, next)
