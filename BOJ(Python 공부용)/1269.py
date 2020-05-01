import sys
from math import sqrt

input = sys.stdin


def lower_bound(left, right, target):
    while left < right:
        mid = (left + right) // 2
        if b[mid] < target:
            left = mid + 1
        else:
            right = mid

    return right


if __name__ == '__main__':
    n, m = map(int, input.readline().split())
    a = [int(x) for x in input.readline().split()]
    b = [int(x) for x in input.readline().split()]

    a.sort()
    b.sort()
    cnt = 0
    for num in a:
        idx = lower_bound(0, len(b) - 1, num)
        if b[idx] == num: cnt += 1

    print(len(a) + len(b) - 2 * cnt)
