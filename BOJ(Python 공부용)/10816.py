import sys

input = sys.stdin
sys.setrecursionlimit(5000)

map = {}

n = int(input.readline())
v = [int(x) for x in input.readline().split()]
for i in v:
    if map.get(i) is None:
        map[i] = 1
    else:
        map[i] += 1
m = int(input.readline())
t = [int(x) for x in input.readline().split()]
for i in t:
    value = map.get(i)
    if value is None:
        print("0 ", end="")
    else:
        print(value, end=" ")
