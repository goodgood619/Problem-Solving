import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    while True:
        n, k = map(int, input.readline().split())
        if n == 0 and k == 0: break
        if k > n - k:
            k = n - k
        p = 1
        for _ in range(k):
            p *= (n - _)

        for _ in range(k, 0, -1):
            p //= _

        print(p)
