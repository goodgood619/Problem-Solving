import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    if n <= 99:
        print(n)
    else:
        ans = 99
        for i in range(100, n + 1):
            p = i
            v = []
            while p > 0:
                v.append(p % 10)
                p //= 10
            v.reverse()
            check = False
            value = v[1] - v[0]
            for j in range(2, len(v)):
                if value == v[j] - v[j - 1]:
                    continue
                else:
                    check = True

            if not check:
                ans += 1
        print(ans)
