import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    visited = [False]*31
    for _ in range(28):
        visited[int(input.readline())] = True

    for i in range(1,31):
        if not visited[i]:
            print(i)
