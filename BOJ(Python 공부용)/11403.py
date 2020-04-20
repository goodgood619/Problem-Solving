#!/usr/bin/env python

n = int(input())
board = [[int(x) for x in input().split()] for _ in range(n)]

for k in range(n):
    for i in range(n):
        for j in range(n):
            if board[i][k] == 1 and board[k][j] == 1:
                board[i][j] = 1

for i in range(n):
    for j in range(n):
        print(board[i][j], end=" ")
    print()
