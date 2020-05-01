import sys

input = sys.stdin

t = int(input.readline())
for _ in range(t):
    x, y = [int(i, 2) for i in input.readline().split()]
    print(bin(x + y)[2:])
