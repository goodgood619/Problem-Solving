import sys

input = sys.stdin
sys.setrecursionlimit(100000)

n = int(input.readline())
cnt = 0


def hanoi(n, st, by, to):
    global cnt
    if n == 1:
        cnt += 1
        return
    else:
        hanoi(n - 1, st, to, by)
        cnt += 1
        hanoi(n - 1, by, st, to)


def hanoi2(n, st, by, to):
    if n == 1:
        print("%d %d" % (st, to))
        return
    else:
        hanoi2(n - 1, st, to, by)
        print("%d %d" % (st, to))
        hanoi2(n - 1, by, st, to)


if n <= 20:
    hanoi(n, 1, 2, 3)
    print(cnt)
    hanoi2(n, 1, 2, 3)
else:
    print(int(pow(2, n)) - 1)
