import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n, x = map(int, input.readline().split())
    v = [int(x) for x in input.readline().split()]
    for ele in v:
        if ele < x:
            print(ele, end=" ")
