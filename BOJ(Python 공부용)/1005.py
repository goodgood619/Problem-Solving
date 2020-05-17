import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    t = int(input.readline())
    for _ in range(t):
        n, k = map(int, input.readline().split())
        make = [int(x) for x in input.readline().split()]
        indegree = [0] * n
        dp = [0] * n
        graph = [[] for _ in range(n)]
        for _ in range(k):
            first, next = map(int, input.readline().split())
            first -= 1
            next -= 1
            graph[first].append(next)
            indegree[next] += 1

        w = int(input.readline())
        w -= 1
        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
                dp[i] = make[i]

        while q:
            here = q.popleft()
            for next in graph[here]:
                indegree[next] -= 1
                if indegree[next] == 0:
                    q.append(next)

                dp[next] = max(dp[next], dp[here] + make[next])

        print(dp[w])
