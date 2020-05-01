import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    p = 2
    while n > 1:
        if n % p == 0:
            n //= p
            print(p)
            p = 2
        else:
            p += 1