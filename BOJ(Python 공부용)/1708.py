import sys
from collections import deque

input = sys.stdin
sys.setrecursionlimit(100000)

n = int(input.readline())
v = []
for _ in range(n):
    x, y = map(int, input.readline().split())
    v.append((x, y))

v.sort()


def ccw(a, b, c):
    return a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1])


up = deque()
down = deque()

up.append(0)
up.append(1)
ptr = 2
while ptr < len(v):
    second = up.pop()
    first = up.pop()
    res = ccw(v[first], v[second], v[ptr])
    if res > 0:
        up.append(first)
        up.append(second)
        up.append(ptr)
        ptr += 1
    else:
        up.append(first)
        if len(up) == 1:
            up.append(ptr)
            ptr += 1

down.append(len(v) - 1)
down.append(len(v) - 2)
ptr = len(v) - 3
while ptr >= 0:
    second = down.pop()
    first = down.pop()
    res = ccw(v[first], v[second], v[ptr])
    if res > 0:
        down.append(first)
        down.append(second)
        down.append(ptr)
        ptr -= 1
    else:
        down.append(first)
        if len(down) == 1:
            down.append(ptr)
            ptr -= 1

m = {}
cnt = 0
length = len(up)
while length > 0:
    length -= 1
    here = up.pop()
    if m.get(here) is None:
        m[here] = 1
        cnt += 1

length = len(down)
while length > 0:
    length -= 1
    here = down.pop()
    if m.get(here) is None:
        m[here] = 1
        cnt += 1

print(cnt)