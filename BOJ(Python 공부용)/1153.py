import sys
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    notPrime = [False] * 1000001
    for i in range(2, int(sqrt(1000000))):
        if notPrime[i]: continue
        for j in range(i * i, 1000001, i):
            notPrime[j] = True
    n = int(input.readline())
    if n < 8:
        print(-1)
        sys.exit(0)
    v = []
    v.append(2)
    if n % 2 == 0:
        v.append(2)
        n -= 4
    else:
        v.append(3)
        n -= 5

    for i in range(2, 1000001):
        if notPrime[i]: continue
        if not notPrime[n - i] and n > i:
            v.append(n - i)
            v.append(i)
            break

    if len(v) != 4:
        print(-1)
    else:
        for a in v:
            print(a, end=" ")
