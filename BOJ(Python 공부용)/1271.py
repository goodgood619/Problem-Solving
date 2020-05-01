import sys

input = sys.stdin

if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    di, mod = n // m, n % m
    print(di)
    print(mod)
