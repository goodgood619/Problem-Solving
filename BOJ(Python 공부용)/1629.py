import sys

input = sys.stdin
sys.setrecursionlimit(10000)


def go(a, b, c):
    if b == 0:
        return 1
    elif b % 2 == 1:
        res = go(a, (b - 1) // 2, c)
        return res * res * a % c
    else:
        res = go(a, b // 2, c)
        return res * res % c


if __name__ == '__main__':
    a, b, c = map(int, input.readline().split())
    print(go(a, b, c))
