import sys

input = sys.stdin
n = int(input.readline())
ans = 0


def go(depth, num):
    global ans
    if depth >= 7: return
    if num <= n:
        ans = max(ans, num)
    go(depth + 1, num * 10 + 4)
    go(depth + 1, num * 10 + 7)


go(0, 0)
print(ans)