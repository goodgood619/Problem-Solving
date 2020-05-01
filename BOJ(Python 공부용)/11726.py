import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    dp = [0] * (n + 1)
    dp[0], dp[1] = 1, 1
    for i in range(2, n + 1):
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007
    print(dp[n])
