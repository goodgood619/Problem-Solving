import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n, m, k = map(int, input.readline().split())
    indegree = [0] * n
    buildcnt = [0] * n
    graph = [[] for _ in range(n)]
    for _ in range(m):
        x, y = map(int, input.readline().split())
        x -= 1
        y -= 1
        indegree[y] += 1
        graph[x].append(y)

    for _ in range(k):
        choice, make = map(int, input.readline().split())
        make -= 1
        if choice == 1:
            if indegree[make] > 0:
                print("Lier!")
                sys.exit(0)
            buildcnt[make] += 1
            for next in graph[make]:
                indegree[next] -= 1

        else:
            if buildcnt[make] == 0:
                print("Lier!")
                sys.exit(0)

            buildcnt[make] -= 1
            if buildcnt[make] == 0:
                for next in graph[make]:
                    indegree[next] += 1

    print("King-God-Emperor")
