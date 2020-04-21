import sys

input = sys.stdin
sys.setrecursionlimit(100)

x, y = map(str, input.readline().split())

s = str(int(x[::-1]) + int(y[::-1]))
print(int(s[::-1]))
