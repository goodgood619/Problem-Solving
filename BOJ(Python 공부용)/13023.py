import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def dfs(here, sum):
    global ok
    if ok or sum >= 5:
        ok = True
        return

    visited[here] = True
    for next in graph[here]:
        if not visited[next]:
            dfs(next, sum + 1)

    visited[here] = False


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, input.readline().split())
        graph[a].append(b)
        graph[b].append(a)

    ok = False
    visited = [False] * n
    for i in range(n):
        if not visited[i]:
            dfs(i, 1)

        if ok: break

    if ok:
        print("1")
    else:
        print("0")
