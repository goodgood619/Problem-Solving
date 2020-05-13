import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(3000)


def dfs(x, y, value):
    v.append((x, y))
    visited[x][y] = True
    for dx, dy in (-1, 0), (1, 0), (0, 1), (0, -1):
        nx, ny = x + dx, y + dy
        if ny == m:
            ny = 0
        elif ny < 0:
            ny = m - 1
        if nx < 0 or nx >= n or ny < 0 or ny >= m or board[nx][ny] != value or visited[nx][ny]: continue
        dfs(nx, ny, value)


# 1 1 2 3
# 1칸
# 시계방향(d = 0) : 3 1 1 2
# 반시계방향(d = 1) : 1 2 3 1
def rotate(i, board, d, k):
    q = deque()
    if d == 0:
        for j in range(m):
            q.append(board[i][j])
        for _ in range(k):
            last = q.pop()
            q.appendleft(last)
        idx = 0
        while q:
            board[i][idx] = q.popleft()
            idx += 1
    else:
        for j in range(m):
            q.append(board[i][j])
        for _ in range(k):
            first = q.popleft()
            q.append(first)
        idx = 0
        while q:
            board[i][idx] = q.popleft()
            idx += 1


if __name__ == '__main__':
    n, m, t = map(int, input.readline().split())
    board = [[int(x) for x in input.readline().split()] for _ in range(n)]
    for _ in range(t):
        x, d, k = map(int, input.readline().split())
        p = x
        x -= 1
        for j in range(x, len(board), p):
            rotate(j, board, d, k)

        visited = [[False] * m for _ in range(n)]
        check = False
        for i in range(n):
            for j in range(m):
                if board[i][j] != 0 and not visited[i][j]:
                    v = []
                    dfs(i, j, board[i][j])
                    if len(v) >= 2:
                        check = True
                        for ele in v:
                            x, y = ele[0], ele[1]
                            board[x][y] = 0

        if not check:
            avg, cnt = 0, 0
            for i in range(n):
                for j in range(m):
                    if board[i][j] != 0:
                        avg += board[i][j]
                        cnt += 1
            if cnt > 0: avg /= cnt
            for i in range(n):
                for j in range(m):
                    if board[i][j] == 0: continue
                    if avg > board[i][j]:
                        board[i][j] += 1
                    elif avg < board[i][j]:
                        board[i][j] -= 1

    sum = 0
    for i in range(n):
        for j in range(m):
            sum += board[i][j]
    print(sum)
