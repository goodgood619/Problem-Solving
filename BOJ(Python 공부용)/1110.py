import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    visited = [False] * 101
    cnt = 0
    if n == 0:
        print(1)
    else:
        visited[n] = True
        while True:
            a, b, c, sum = 0, 0, 0, 0
            if n < 10:
                a = 0
                b = n
                c = a + b
                if c >= 10:
                    sum = b * 10 + c % 10
                else:
                    sum = b * 10 + c
                cnt += 1
                n = sum
            else:
                a = n // 10
                b = n % 10
                c = a + b
                if c >= 10:
                    sum = b * 10 + c % 10
                else:
                    sum = b * 10 + c
                cnt += 1
                n = sum
            if visited[n]: break
        print(cnt)
