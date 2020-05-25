import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def bfs(r1, c1, r2, c2):
    q = deque()
    q.append((r1, c1, 0))
    visited = [[False] * n for _ in range(n)]
    visited[r1][c1] = True
    while q:
        x, y, dist = q.popleft()
        if x == r2 and y == c2:
            return dist
        for dx, dy in (-2, -1), (-2, 1), (0, -2), (0, 2), (2, -1), (2, 1):
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny]: continue
            q.append((nx, ny, dist + 1))
            visited[nx][ny] = True

    return -1


if __name__ == '__main__':
    n = int(input.readline())
    r1, c1, r2, c2 = map(int, input.readline().split())
    print(bfs(r1, c1, r2, c2))
