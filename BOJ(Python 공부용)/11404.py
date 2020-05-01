import sys

input = sys.stdin

n = int(input.readline())
m = int(input.readline())
board = [[int(1e9)] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    board[i][i] = 0
for _ in range(m):
    here, next, cost = map(int, input.readline().split())
    if board[here][next] > cost:
        board[here][next] = cost

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if board[i][j] > board[i][k] + board[k][j]:
                board[i][j] = board[i][k] + board[k][j]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j or board[i][j] == int(1e9):
            print("0", end=" ")
        else:
            print(board[i][j], end=" ")
    print()
