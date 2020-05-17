import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def lowerbound(left, right, target):
    while left < right:
        mid = (left + right) // 2
        if v[mid] < target:
            left = mid + 1
        else:
            right = mid
    return right


if __name__ == '__main__':
    notVisited = [False] * 10001
    for i in range(2, int(sqrt(10001))):
        if notVisited[i]: continue
        for j in range(i * i, 10001, i):
            notVisited[j] = True
    v = []
    for i in range(2, 10001):
        if not notVisited[i]:
            v.append(i)
    t = int(input.readline())
    for _ in range(t):
        n = int(input.readline())
        diff, ans1, ans2 = int(1e9), 0, 0
        for i in range(len(v)):
            a = v[i]
            idx = lowerbound(0, len(v), n - a)
            if idx == len(v): continue
            if v[idx] == n - a:
                if diff > abs(v[idx] - a):
                    diff = abs(v[idx] - a)
                    ans1 = min(v[idx], a)
                    ans2 = max(v[idx], a)

        print(ans1, end=" ")
        print(ans2)
