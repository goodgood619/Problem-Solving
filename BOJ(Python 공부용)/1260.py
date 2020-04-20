def dfs(v) :
    print(v,end=" ")
    visited[v] = True
    for next in graph[v]:
        if not(visited[next]):
            dfs(next)

def bfs(v):
    q = [v]
    visited = [False]*(n+1)
    while q:
        here = q.pop(0)
        if not(visited[here]):
            visited[here] = True
            print(here,end = " ")
            for next in graph[here]:
                if not(visited[next]):
                    q.append(next)
                    
n,m,v = map(int,input().split())
graph = [[] for i in range(n+1)]
visited = [False]*(n+1)
for i in range(m):
    here,next = map(int,input().split())
    graph[here].append(next)
    graph[next].append(here)


for e in graph:
    e.sort()

dfs(v)
print()
bfs(v)
