import sys

input = sys.stdin


def upper_bound(left, right, target):
    while left < right:
        mid = (left + right) // 2
        if a[mid] <= target:
            left = mid + 1
        else:
            right = mid

    return right


if __name__ == '__main__':
    t = int(input.readline())
    for _ in range(t):
        n, m = map(int, input.readline().split())
        a = [int(x) for x in input.readline().split()]
        b = [int(x) for x in input.readline().split()]
        a.sort()
        b.sort()
        ans = 0
        for val in b:
            idx = upper_bound(0, len(a), val)
            if idx == len(a): continue
            ans += len(a) - idx

        print(ans)