import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    a, b, c = map(int, input.readline().split())
    if c <= b:
        print(-1)
    else:
        num = a / (c - b)
        print(int(num) + 1)
