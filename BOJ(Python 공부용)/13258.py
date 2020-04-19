import sys

sys.setrecursionlimit(100000)

n = int(sys.stdin.readline())
v = list(map(int, sys.stdin.readline().split()))
a = float(v[0])
b = 0.0
for i in range(1, len(v)):
    b += v[i]

j = int(sys.stdin.readline())
c = int(sys.stdin.readline())
for i in range(1, c + 1):
    ta = float(a + j * a / (a + b))
    tb = float(b + j * b / (a + b))
    a = ta
    b = tb

print('%.9f' % a)
