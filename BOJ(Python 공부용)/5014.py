import sys
from collections import deque

input = sys.stdin
sys.setrecursionlimit(5000)


def bfs(s, g, f, u, d):
    q = deque()
    q.append((s, 0))
    visited[s] = True
    ans = int(1e9)
    while q:
        here, dist = q.popleft()
        if here == g:
            ans = dist
            break
        nx1 = here + u
        nx2 = here - d
        if nx1 <= f and not visited[nx1]:
            visited[nx1] = True
            q.append((nx1, dist + 1))

        if nx2 >= 1 and not visited[nx2]:
            visited[nx2] = True
            q.append((nx2, dist + 1))

    if ans == int(1e9):
        print("use the stairs")
    else:
        print(ans)


f, s, g, u, d = map(int, input.readline().split())
visited = [False] * (f + 1)
bfs(s, g, f, u, d)