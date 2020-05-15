import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def dfs(here, c):
    visited[here] = True
    color[here] = c
    for next in graph[here]:
        if not visited[next]:
            dfs(next, 3 - c)


if __name__ == '__main__':
    t = int(input.readline())
    for _ in range(t):
        n, m = map(int, input.readline().split())
        graph = [[] for _ in range(n + 1)]
        visited = [False] * (n + 1)
        color = [-1] * (n + 1)
        for _ in range(m):
            a, b = map(int, input.readline().split())
            graph[a].append(b)
            graph[b].append(a)

        for i in range(1, n + 1):
            if not visited[i]:
                dfs(i, 1)

        no = False
        for i in range(1, n + 1):
            curColor = color[i]
            for next in graph[i]:
                nextColor = color[next]
                if curColor == nextColor:
                    no = True
                    break

            if no:
                break

        if no:
            print("impossible")
        else:
            print("possible")
