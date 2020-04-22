import sys

input = sys.stdin
sys.setrecursionlimit(10000000)

n = int(input.readline())
board = [[int(x) for x in input.readline().split()] for _ in range(n)]
visited = [False] * n
Min = int(1e9)


def dfs(index, cnt, depth):
    global Min
    if cnt == depth:
        home = []
        away = []
        for i in range(len(visited)):
            if visited[i]:
                home.append(i)
            else:
                away.append(i)

        hometotal = 0
        awaytotal = 0
        for i in range(len(home)):
            for j in range(len(home)):
                hometotal += board[home[i]][home[j]]
                awaytotal += board[away[i]][away[j]]

        Min = min(Min, abs(awaytotal - hometotal))
        return

    for i in range(index, len(visited)):
        if not visited[i]:
            visited[i] = True
            dfs(i + 1, cnt + 1, depth)
            visited[i] = False


dfs(0, 0, n / 2)
print(Min)
