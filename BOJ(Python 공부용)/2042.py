import sys

sys.setrecursionlimit(100000000)


def update(index, value):
    index += h - 1
    v[index] = value
    while index > 1:
        index //= 2
        v[index] = v[index * 2] + v[index * 2 + 1]


def query(nodenum, left, right, nodeleft, noderight):
    if nodeleft > right or left > noderight:
        return 0
    elif left <= nodeleft and noderight <= right:
        return v[nodenum]
    mid = (nodeleft + noderight) // 2
    return query(nodenum * 2, left, right, nodeleft, mid) + query(nodenum * 2 + 1, left, right, mid + 1, noderight)


n, m, k = map(int, sys.stdin.readline().split())
h = 1
while h < n:
    h *= 2
v = [0] * (2 * h)

for i in range(1, n + 1):
    num = int(sys.stdin.readline())
    update(i, num)

for i in range(0, m + k):
    a, b, c = map(int, sys.stdin.readline().split())
    if a == 1:
        update(b, c)
    else:
        print(query(1, b, c, 1, h))
