import sys
from collections import deque
from math import sqrt

input = sys.stdin
sys.setrecursionlimit(10000000)


def lowerbound(left, right, num):
    while left < right:
        mid = (left + right) // 2
        if v[mid] < num:
            left = mid + 1
        else:
            right = mid
    return right


def makenum(str):
    sum = 0
    idx = 0
    for i in range(len(str) - 1, -1, -1):
        sum += int(str[i]) * int(pow(10, idx))
        idx += 1
    return sum


def bfs(st, en):
    visited = [False] * 10001
    visited[st] = True
    q = deque()
    q.append((st, 0))
    temp = -1
    while q:
        num, cnt = q.popleft()
        if num == en:
            temp = cnt
            break
        sb = list(str(num))
        for i in range(len(sb)):
            c = sb[i]
            for j in range(10):
                if int(c) == j: continue
                ssb = list(str(num))
                ssb[i] = str(j)
                newnum = makenum(ssb)
                idx = lowerbound(0, len(v), newnum)
                if idx == len(v): continue
                if v[idx] == newnum and not visited[newnum] and 1000 <= newnum < 10000:
                    q.append((newnum, cnt + 1))
                    visited[newnum] = True

    return temp


notprime = [False] * 10001
for i in range(2, int(sqrt(10000))):
    for j in range(i * i, 10000, i):
        notprime[j] = True

v = []
for i in range(2, 10000):
    if not notprime[i]:
        v.append(i)

t = int(input.readline())
for _ in range(t):
    n, m = map(int, input.readline().split())
    ans = bfs(n, m)
    if ans == -1:
        print("Impossible")
    else:
        print(ans)
