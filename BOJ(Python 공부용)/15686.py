import sys

input = sys.stdin
sys.setrecursionlimit(500000)

n, m = map(int, input.readline().split())
board = [[int(x) for x in input.readline().split()] for _ in range(n)]
v = []
ans = int(1e9)


def bfs():
    global ans
    temp = []
    for i in range(len(v)):
        if visited[i]:
            temp.append((v[i][0], v[i][1]))

    home = []
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                home.append((i, j))

    tempans = 0
    for i in range(len(home)):
        tempdist = int(1e9)
        for j in range(len(temp)):
            tempdist = min(tempdist, abs(home[i][0] - temp[j][0]) + abs(home[i][1] - temp[j][1]))
        tempans += tempdist

    ans = min(ans, tempans)


def dfs(here, cnt, depth):
    if cnt == depth:
        bfs()
        return
    for i in range(here, len(v), 1):
        if not visited[i]:
            visited[i] = True
            dfs(i + 1, cnt + 1, depth)
            visited[i] = False


for i in range(n):
    for j in range(n):
        if board[i][j] == 2:
            v.append((i, j))

visited = [False] * len(v)
dfs(0, 0, m)
print(ans)