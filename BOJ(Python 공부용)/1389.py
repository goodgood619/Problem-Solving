import sys

input = sys.stdin
sys.setrecursionlimit(5000)

n, m = map(int, input.readline().split())
board = [[int(1e9)] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    board[i][i] = 0

for _ in range(m):
    left, right = map(int, input.readline().split())
    board[left][right] = 1
    board[right][left] = 1

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if board[i][j] > board[i][k] + board[k][j]:
                board[i][j] = board[i][k] + board[k][j]

ans = int(1e9)
num = [0] * (n + 1)
for i in range(1, n + 1):
    Max = 0
    for j in range(1, n + 1):
        if i != j:
            Max += board[i][j]

    ans = min(ans, Max)
    num[i] = Max

for i in range(1, n + 1):
    if ans == num[i]:
        print(i)
        break