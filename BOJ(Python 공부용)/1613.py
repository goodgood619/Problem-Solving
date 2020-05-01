import sys

input = sys.stdin
sys.setrecursionlimit(10000)

if __name__ == '__main__':
    n, k = map(int, input.readline().split())
    board = [[0] * (n + 1) for _ in range(n + 1)]
    for _ in range(k):
        a, b = map(int, input.readline().split())
        board[a][b] = -1
        board[b][a] = 1

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if board[i][k] == 1 and board[k][j] == 1:
                    board[i][j] = 1
                elif board[i][k] == -1 and board[k][j] == -1:
                    board[i][j] = -1

    t = int(input.readline())
    for _ in range(t):
        a, b = map(int, input.readline().split())
        print(board[a][b])
