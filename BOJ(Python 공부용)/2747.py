import sys


def fib(n):
    prev, curr = 0, 1
    for _ in range(n):
        prev, curr = curr, prev + curr
    return prev


if __name__ == '__main__':
    n = int(sys.stdin.readline())
    print(fib(n))
