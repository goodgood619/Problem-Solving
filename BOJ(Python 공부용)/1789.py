import sys
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    s = int(input.readline())
    i, sum, idx = 1, 0, 0
    arr = [0] * 100001
    while True:
        sum += i
        arr[i] = i
        if sum > s:
            idx = i - 1
            break
        i += 1
    print(idx)
