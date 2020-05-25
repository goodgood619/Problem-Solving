import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def dfs(here, num):
    if map.get(num) is None:
        return
    if here == n:
        for value in temp:
            print(value, end=" ")
        sys.exit(0)

    if num % 3 == 0:
        temp.append(num // 3)
        dfs(here + 1, num // 3)
        temp.pop()

    temp.append(num * 2)
    dfs(here + 1, num * 2)
    temp.pop()


if __name__ == '__main__':
    n = int(input.readline())
    v = [int(x) for x in input.readline().split()]
    map = {}
    for value in v:
        if map.get(value) is None:
            map[value] = 1

    temp = []
    for value in v:
        temp.append(value)
        dfs(1, value)
        temp.pop()
