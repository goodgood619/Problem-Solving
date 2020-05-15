import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    v = [int(x) for x in input.readline().split()]
    mid = 0
    for value in v:
        mid += value

    mid //= n
    mid += 10
    idx = 0
    ans, ans2 = int(1e9), 0
    for i in range(mid, 0, -1):
        for value in v:
            ans2 += abs(i - value)

        if ans2 <= ans:
            ans = ans2
            idx = i
        ans2 = 0

    print(idx)
