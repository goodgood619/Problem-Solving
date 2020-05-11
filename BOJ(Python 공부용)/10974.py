import sys
from math import sqrt

input = sys.stdin


def go(cnt, depth, temp, visited):
    if cnt == depth:
        for value in temp:
            print(value, end=" ")
        print()
        return

    for i in range(n):
        if not visited[i]:
            visited[i] = True
            temp.append(i + 1)
            go(cnt + 1, depth, temp, visited)
            temp.pop()
            visited[i] = False


if __name__ == '__main__':
    n = int(input.readline())
    temp = []
    visited = [False] * n
    go(0, n, temp, visited)
