import itertools
import sys
from collections import deque
from heapq import heappush, heappop
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    q = deque()
    cnt = 0
    flag = False
    for i in range(1, n + 1):
        q.append(i)

    while cnt != n:
        if not flag:
            if cnt == n - 1:
                print(q.popleft())
                break
            q.popleft()
            flag = True
            cnt += 1
        else:
            front = q.popleft()
            q.append(front)
            flag = False
