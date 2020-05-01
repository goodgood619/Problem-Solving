import sys

input = sys.stdin

if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    if n > m:
        temp = n
        n = m
        m = temp
    a, b = m * (m + 1) // 2, n * (n - 1) // 2
    print(a - b)
