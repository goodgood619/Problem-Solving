import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n, p = map(int, input.readline().split())
    map = {}
    cnt, cur = 1, 1
    map[n] = 1
    gob = n
    while True:
        temp = n
        temp *= gob
        temp %= p
        n = temp
        if map.get(n) is not None:
            cur = map.get(n)
            break
        cnt += 1
        map[n] = cnt

    print(cnt - cur + 1)
