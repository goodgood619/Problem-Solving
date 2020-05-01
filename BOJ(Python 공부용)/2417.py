import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    left, right, ans = 1, n, 0
    while left <= right:
        mid = (left + right) // 2
        temp = mid
        mid = mid * mid
        if mid >= n:
            ans = temp
            right = temp - 1
        else:
            left = temp + 1

    print(ans)
