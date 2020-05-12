import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    t = int(input.readline())
    for _ in range(t):
        n = int(input.readline())
        temp = n * n
        sum, cnt = 0, 0
        ok = False

        while temp > 0:
            sum += int((temp % 10) * pow(10, cnt))
            if sum == n:
                ok = True
                break
            temp //= 10
            cnt += 1
        if ok:
            print("YES")
        else:
            print("NO")
