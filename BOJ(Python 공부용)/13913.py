import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def bfs(n, k):
    q = deque()
    visited = [False] * 100001
    q.append((n, 0))
    visited[n] = True
    ans = 0
    while q:
        here, cost = q.popleft()
        if here == k:
            ans = cost
            break

        nx1, nx2, nx3 = here + 1, here - 1, here * 2
        if 0 <= nx1 <= 100000 and not visited[nx1]:
            visited[nx1] = True
            path[nx1] = here
            q.append((nx1, cost + 1))
        if 0 <= nx2 <= 100000 and not visited[nx2]:
            visited[nx2] = True
            path[nx2] = here
            q.append((nx2, cost + 1))
        if 0 <= nx3 <= 100000 and not visited[nx3]:
            visited[nx3] = True
            path[nx3] = here
            q.append((nx3, cost + 1))

    return ans


if __name__ == '__main__':
    n, k = map(int, input.readline().split())
    path = [-1] * 100001
    print(bfs(n, k))
    v = []
    p = k
    while p != -1:
        v.append(p)
        p = path[p]
    v.reverse()
    for i in v:
        print(i, end=" ")
