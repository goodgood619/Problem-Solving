import sys

input = sys.stdin


def dfs(here, graph, visited):
    visited[here] = True
    for next in graph[here]:
        if not visited[next]:
            dfs(next, graph, visited)


if __name__ == '__main__':
    n = int(input.readline())
    m = int(input.readline())
    graph = [[] for _ in range(n + 1)]
    visited = [False] * (n + 1)
    for _ in range(m):
        here, next = map(int, input.readline().split())
        graph[here].append(next)
        graph[next].append(here)

    dfs(1, graph, visited)
    cnt = 0
    for i in range(1, n + 1):
        if visited[i]: cnt += 1

    print(cnt - 1)
