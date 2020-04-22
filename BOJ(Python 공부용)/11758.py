import sys

input = sys.stdin
sys.setrecursionlimit(100000)


def ccw(a, b, c):
    return a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1])


a, b = map(int, input.readline().split())
c, d = map(int, input.readline().split())
e, f = map(int, input.readline().split())

res = ccw((a, b), (c, d), (e, f))
if res > 0:
    print(1)
elif res < 0:
    print(-1)
else:
    print(0)