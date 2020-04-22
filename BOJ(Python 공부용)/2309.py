import sys

input = sys.stdin
sys.setrecursionlimit(5000)
v = []
temp = []
visited = [False] * 9


def go(here, cnt, depth):
    if cnt == depth:
        sum = 0
        for num in temp:
            sum += num

        if sum != 100: return
        for num in temp:
            print(num)
        sys.exit(0)
    for i in range(here, 9, 1):
        if not visited[i]:
            visited[i] = True
            temp.append(v[i])
            go(i + 1, cnt + 1, depth)
            temp.remove(v[i])
            visited[i] = False


for _ in range(9):
    v.append(int(input.readline()))

v.sort()
go(0, 0, 7)