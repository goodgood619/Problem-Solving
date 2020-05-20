import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def lowerbound(left, right, value):
    while left < right:
        mid = (left + right) // 2
        if v1[mid] < value:
            left = mid + 1
        else:
            right = mid

    return right


if __name__ == '__main__':
    t = int(input.readline())
    for _ in range(t):
        n = int(input.readline())
        v1 = [int(x) for x in input.readline().split()]
        v1.sort()
        m = int(input.readline())
        v2 = [int(x) for x in input.readline().split()]
        for value in v2:
            idx = lowerbound(0, len(v1) - 1, value)
            if v1[idx] == value:
                print(1)
            else:
                print(0)
