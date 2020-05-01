import sys

input = sys.stdin
from math import sqrt


def check(value):
    map = {}
    ok = False
    while True:
        if value == 1:
            ok = True
            break
        if map.get(value) == 1:
            break
        map[value] = 1
        sum = 0
        while value > 0:
            sum += (value % 10) * (value % 10)
            value //= 10
        value = sum
    return ok


if __name__ == '__main__':
    n = int(input.readline())
    notvisited = [False] * (n + 1)
    for i in range(2, int(sqrt(n))):
        if notvisited[i]:
            continue
        for j in range(i * i, n + 1, i):
            notvisited[j] = True

    for i in range(2, n + 1):
        if notvisited[i]: continue
        p = i
        if check(p): print(i)
