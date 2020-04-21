import sys

input = sys.stdin
sys.setrecursionlimit(500000)


def dfs(here, c):
    visited[here] = True
    color[here] = c
    for next in graph[here]:
        if not visited[next]:
            dfs(next, 3 - c)


k = int(input.readline())
for _ in range(k):
    V, E = map(int, input.readline().split())
    graph = [[] for _ in range(V + 1)]
    visited = [False] * (V + 1)
    color = [0] * (V + 1)
    for _ in range(E):
        here, next = map(int, input.readline().split())
        graph[here].append(next)
        graph[next].append(here)

    for i in range(1, V + 1):
        if not visited[i]:
            dfs(i, 1)

    no = False
    for i in range(1, V + 1):
        for next in graph[i]:
            if color[next] == color[i]:
                no = True
                break

        if no: break

    if no:
        print("NO")
    else:
        print("YES")
