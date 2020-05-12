import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def go(x1, y1, x2, y2, dir):
    if x1 == n - 1 and y1 == n - 1 or x2 == n - 1 and y2 == n - 1: return 1
    ret = 0
    if dir == 0:
        if y2 + 1 < n and board[x2][y2 + 1] == 0: ret += go(x2, y2, x2, y2 + 1, dir)
        if y2 + 1 < n and x2 + 1 < n and board[x2][y2 + 1] == 0 and board[x2 + 1][y2] == 0 and board[x2 + 1][
            y2 + 1] == 0:
            ret += go(x2, y2, x2 + 1, y2 + 1, 2)
    elif dir == 1:
        if x2 + 1 < n and board[x2 + 1][y2] == 0: ret += go(x2, y2, x2 + 1, y2, dir)
        if y2 + 1 < n and x2 + 1 < n and board[x2][y2 + 1] == 0 and board[x2 + 1][y2] == 0 and board[x2 + 1][
            y2 + 1] == 0:
            ret += go(x2, y2, x2 + 1, y2 + 1, 2)
    else:
        if y2 + 1 < n and board[x2][y2 + 1] == 0: ret += go(x2, y2, x2, y2 + 1, 0)
        if x2 + 1 < n and board[x2 + 1][y2] == 0: ret += go(x2, y2, x2 + 1, y2, 1)
        if y2 + 1 < n and x2 + 1 < n and board[x2][y2 + 1] == 0 and board[x2 + 1][y2] == 0 and board[x2 + 1][
            y2 + 1] == 0:
            ret += go(x2, y2, x2 + 1, y2 + 1, 2)
    return ret


if __name__ == '__main__':
    n = int(input.readline())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    print(go(0, 0, 0, 1, 0))
