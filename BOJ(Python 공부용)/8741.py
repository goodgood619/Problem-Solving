import sys

input = sys.stdin

k = int(input.readline())
for _ in range(k):
    print("1", end="")
for _ in range(k - 1):
    print("0", end="")
