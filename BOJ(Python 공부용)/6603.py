#!/usr/bin/env python

import sys

sys.setrecursionlimit(100000)
lotto = [0] * 6


def go(index, cnt, depth, index2):
    if cnt == depth:
        print(' '.join(map(str, lotto)))
        return

    for i in range(index, len(temp)):
        if not visited[i]:
            visited[i] = True
            lotto[index2] = temp[i]
            go(i + 1, cnt + 1, depth, index2 + 1)
            lotto[index2] = 0
            visited[i] = False


while True:
    temp = list(map(int, sys.stdin.readline().split()))
    if temp[0] == 0:
        break
    visited = [False] * len(temp)
    go(1, 0, 6, 0)
    print()
