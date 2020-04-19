import sys

sys.setrecursionlimit(50000000)

n = int(sys.stdin.readline())
map = {}
v = []
for _ in range(n):
    num = int(sys.stdin.readline())
    map[num] = map.get(num, 0) + 1

for k in map.keys():
    v.append((k, map.get(k)))

v.sort(key=lambda v: (-v[1], v[0]))

print(v[0][0])
