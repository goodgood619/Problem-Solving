import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    m = int(input.readline())
    board = [[0] * (n + 1) for _ in range(n + 1)]
    for _ in range(m):
        a, b = map(int, input.readline().split())
        board[a][b] = 1
        board[b][a] = -1

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if board[i][k] == 1 and board[k][j] == 1:
                    board[i][j] = 1
                elif board[i][k] == -1 and board[k][j] == -1:
                    board[i][j] = -1

    for i in range(1, n + 1):
        cnt = 0
        for j in range(1, n + 1):
            if i == j:
                continue
            if board[i][j] == 0:
                cnt += 1
        print(cnt)
