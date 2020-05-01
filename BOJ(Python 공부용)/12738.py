import sys

input = sys.stdin


def lower_bound(left, right, target):
    while left < right:
        mid = (left + right) // 2
        if dp[mid] < target:
            left = mid + 1
        else:
            right = mid
    return right


if __name__ == '__main__':
    n = int(input.readline())
    dp = [0] * (n + 1)
    dp[0] = int(-2e9)
    arr = [int(x) for x in input.readline().split()]
    en = 0
    for i in range(n):
        idx = lower_bound(0, en, arr[i])
        dp[idx] = arr[i]
        if idx == en:
            en += 1
    print(en)
