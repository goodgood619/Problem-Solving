import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def gcd(a, b):
    if a % b == 0: return b
    return gcd(b % a, a)


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    res = gcd(n, m)
    print(res)
    print(n // res * m)
