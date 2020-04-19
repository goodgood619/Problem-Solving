import sys

input = sys.stdin
sys.setrecursionlimit(50000000)

n = int(input.readline())
map1 = {}
map2 = {}
visited = [False] * n
k = 0
for i in range(n):
    temp = input.readline().strip("\n")
    a, b = temp.split()
    if b == "enter":
        map1[a] = k
        map2[k] = a
        k += 1
    elif b == "leave":
        visited[map1.get(a)] = True

v = []
for i in map2.keys():
    if not visited[i]:
        v.append(map2.get(i))

v.sort()
for i in range(len(v) - 1, -1, -1):
    print(v[i])
