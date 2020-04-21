import sys

input = sys.stdin
sys.setrecursionlimit(30000)

n = int(input.readline())
graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)
Max = 0
st = 0


def dfs(here, curcost):
    global Max, st
    visited[here] = True
    if Max < curcost:
        st = here
        Max = curcost
    for i in graph[here]:
        next = i[0]
        nextcost = i[1]
        if not visited[next]:
            dfs(next, curcost + nextcost)
    visited[here] = False


for _ in range(n - 1):
    here, next, cost = map(int, input.readline().split())
    graph[here].append((next, cost))
    graph[next].append((here, cost))

dfs(1, 0)
Max = 0
dfs(st, 0)
print(Max)