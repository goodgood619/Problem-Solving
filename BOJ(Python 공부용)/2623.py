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
        v = [int(x) for x in input.readline().split()]
        for j in range(len(v)):
            if j <= 1:
                continue
            else:
                first, next = v[j - 1], v[j]
                first -= 1
                next -= 1
                indegree[next] += 1
                graph[first].append(next)

    for i in range(n):
        if indegree[i] == 0:
            q.append(i)

    ans = []
    while q:
        here = q.popleft()
        ans.append(here)
        for next in graph[here]:
            indegree[next] -= 1
            if indegree[next] == 0:
                q.append(next)

    if len(ans) != n:
        print(0)
    else:
        for here in ans:
            print(here + 1)
