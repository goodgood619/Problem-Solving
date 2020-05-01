import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    arr = [int(x) for x in input.readline().split()]
    dp = [0] * (n + 1)
    ans = arr[0]
    for i in range(n):
        dp[i] = arr[i]
        for j in range(0, i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] + arr[i])
                ans = max(ans, dp[i])

    print(ans)
