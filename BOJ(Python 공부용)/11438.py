import sys

input = sys.stdin
sys.setrecursionlimit(200000)
M = 0


def dfs(now, level):
    global M
    if M < level:
        M = level
    depth[now] = level
    for next in v[now]:
        if depth[next] != 0: continue
        dfs(next, level + 1)
        par[next][0] = now


def Lca(a, b):
    if depth[a] < depth[b]:
        temp = a
        a = b
        b = temp

    dif = depth[a] - depth[b]
    for i in range(18):
        if dif & (1 << i):
            a = par[a][i]

    if a != b:
        for i in range(17, -1, -1):
            if par[a][i] != par[b][i]:
                a = par[a][i]
                b = par[b][i]

        a = par[a][0]

    return a


if __name__ == '__main__':
    n = int(input.readline())
    v = [[0] for _ in range(n + 1)]
    par = [[0] * 20 for _ in range(n + 1)]
    depth = [0] * (n + 1)
    for i in range(n - 1):
        a, b = map(int, input.readline().split())
        v[a].append(b)
        v[b].append(a)

    dfs(1, 1)
    for i in range(1, 18):
        for j in range(1, n + 1):
            par[j][i] = par[par[j][i - 1]][i - 1]

    m = int(input.readline())
    for _ in range(m):
        a, b = map(int, input.readline().split())
        print(Lca(a, b))
