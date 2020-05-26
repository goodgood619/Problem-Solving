import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n, k = map(int, input.readline().split())
    coin = []
    for _ in range(n):
        coin.append(int(input.readline()))

    cnt = 0
    for i in range(len(coin) - 1, -1, -1):
        if k == 0: break
        if k < coin[i]: continue
        rest = k // coin[i]
        k = k - rest * coin[i]
        cnt += rest

    print(cnt)