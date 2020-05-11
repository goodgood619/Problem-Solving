import sys
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(1000)


def dfs(x, y, cnt, depth, temp, map, board):
    if cnt == depth:
        sum, idx = 0, 5
        for value in temp:
            sum += value * pow(10, idx)
            idx -= 1
        if map.get(sum) is None:
            map[sum] = 1

        return

    for dx, dy in (-1, 0), (1, 0), (0, -1), (0, 1):
        nx, ny = x + dx, y + dy
        if nx < 0 or nx >= 5 or ny < 0 or ny >= 5: continue
        temp.append(board[nx][ny])
        dfs(nx, ny, cnt + 1, depth, temp, map, board)
        temp.pop()


if __name__ == '__main__':
    board = [[int(x) for x in input.readline().split()] for _ in range(5)]
    map = {}
    for i in range(5):
        for j in range(5):
            temp = []
            temp.append(board[i][j])
            dfs(i, j, 1, 6, temp, map, board)

    print(len(map))
