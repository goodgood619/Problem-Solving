import sys

input = sys.stdin
sys.setrecursionlimit(5000)


def lowerbound(left, right, num):
    while left < right:
        mid = (left + right) // 2
        if v[mid] < num:
            left = mid + 1
        else:
            right = mid
    return right


n = int(input.readline())
v = [int(x) for x in input.readline().split()]
v.sort()
m = int(input.readline())
t = [int(x) for x in input.readline().split()]
for i in t:
    res = lowerbound(0, len(v) - 1, i)
    if v[res] == i:
        print("1 ", end="")
    else:
        print("0 ", end="")
