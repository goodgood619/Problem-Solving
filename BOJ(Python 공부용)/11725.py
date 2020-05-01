import sys

input = sys.stdin
sys.setrecursionlimit(120000)


def dfs(here, par):
    parent[here] = par
    visited[here] = True
    for next in graph[here]:
        if not visited[next]:
            dfs(next, here)


if __name__ == '__main__':
    n = int(input.readline())
    graph = [[] for _ in range(n + 1)]
    parent = [-1] * (n + 1)
    visited = [False] * (n + 1)
    for _ in range(n - 1):
        a, b = map(int, input.readline().split())
        graph[a].append(b)
        graph[b].append(a)

    dfs(1, 0)
    for i in range(2, n + 1):
        print(parent[i])
