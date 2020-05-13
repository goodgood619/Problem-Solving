import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(2000)


def bfs():
    plus = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if board[i][j] > 0:
                cnt = 0
                for dx, dy in (-1, 0), (1, 0), (0, 1), (0, -1):
                    nx, ny = i + dx, j + dy
                    if nx < 0 or nx >= n or ny < 0 or ny >= m or board[nx][ny] == -1: continue
                    cnt += 1
                    plus[nx][ny] += board[i][j] // 5

                board[i][j] = board[i][j] - cnt * (board[i][j] // 5)

    for i in range(n):
        for j in range(m):
            board[i][j] += plus[i][j]


## 오른쪽-> 위-> 왼쪽 -> 아래
def up():
    q = deque()
    tx, ty = sx, sy
    for dx, dy in (0, 1), (-1, 0), (0, -1), (1, 0):
        while 0 <= tx + dx < n and 0 <= ty + dy < m and board[tx + dx][ty + dy] != -1:
            q.append(board[tx + dx][ty + dy])
            tx += dx
            ty += dy

    tx, ty = sx, sy + 1
    board[tx][ty] = 0
    for dx, dy in (0, 1), (-1, 0), (0, -1), (1, 0):
        while 0 <= tx + dx < n and 0 <= ty + dy < m and board[tx + dx][ty + dy] != -1:
            board[tx + dx][ty + dy] = q.popleft()
            tx += dx
            ty += dy


def down():
    q = deque()
    tx, ty = ex, ey
    for dx, dy in (0, 1), (1, 0), (0, -1), (-1, 0):
        while 0 <= tx + dx < n and 0 <= ty + dy < m and board[tx + dx][ty + dy] != -1:
            q.append(board[tx + dx][ty + dy])
            tx += dx
            ty += dy

    tx, ty = ex, ey + 1
    board[tx][ty] = 0
    for dx, dy in (0, 1), (1, 0), (0, -1), (-1, 0):
        while 0 <= tx + dx < n and 0 <= ty + dy < m and board[tx + dx][ty + dy] != -1:
            board[tx + dx][ty + dy] = q.popleft()
            tx += dx
            ty += dy


if __name__ == '__main__':
    n, m, t = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    sx, sy, ex, ey = -1, -1, -1, -1
    for i in range(n):
        for j in range(m):
            if board[i][j] == -1:
                if sx == -1 and sy == -1:
                    sx, sy = i, j
                else:
                    ex, ey = i, j

    for _ in range(t):
        bfs()
        down()
        up()

    sum = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] == -1: continue
            sum += board[i][j]
    print(sum)
