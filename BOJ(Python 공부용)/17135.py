import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin


def move(newBoard):
    for i in range(len(newBoard) - 2, -1, -1):
        for j in range(m):
            newBoard[i + 1][j] = newBoard[i][j]

    for j in range(m):
        newBoard[0][j] = 0


def bfs():
    global ans
    newBoard = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            newBoard[i][j] = board[i][j]
    die = 0
    while True:
        if check(newBoard): break
        attack = []
        for here in arrow:
            ax, ay = here // m, here % m
            temp = []
            for i in range(n):
                for j in range(m):
                    if abs(ax - i) + abs(ay - j) <= d and newBoard[i][j] == 1:
                        temp.append((abs(ax - i) + abs(ay - j), j, i))

            temp.sort()
            if len(temp) >= 1:
                t, y, x = temp[0][0], temp[0][1], temp[0][2]
                attack.append((x, y))

        for value in attack:
            x, y = value[0], value[1]
            if newBoard[x][y] == 1:
                newBoard[x][y] = 0
                die += 1
        move(newBoard)

    ans = max(ans, die)


def check(newBoard):
    for i in range(n):
        for j in range(m):
            if newBoard[i][j] != 0:
                return False
    return True


def dfs(here, cnt, depth):
    if cnt == depth:
        bfs()
        return

    for i in range(here, m):
        if not visited[i]:
            visited[i] = True
            arrow.append(v[i])
            dfs(i + 1, cnt + 1, depth)
            arrow.pop()
            visited[i] = False


if __name__ == '__main__':
    n, m, d = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    start = n * m
    v = []
    arrow = []
    ans = 0
    visited = [False] * m
    for _ in range(m):
        v.append(start)
        start += 1

    dfs(0, 0, 3)
    print(ans)
