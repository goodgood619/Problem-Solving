import sys

input = sys.stdin
sys.setrecursionlimit(5000)
n, s = map(int, input.readline().split())
v = [int(x) for x in input.readline().split()]
visited = [False] * n
ans = 0


def dfs(here, cnt, sum, depth):
    global ans
    if cnt == depth:
        if sum == s:
            ans += 1
        return

    for i in range(here, len(v), 1):
        if not visited[i]:
            visited[i] = True
            dfs(i + 1, cnt + 1, sum + v[i], depth)
            visited[i] = False


for i in range(1, n + 1):
    dfs(0, 0, 0, i)

print(ans)