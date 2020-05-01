import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    dp = [0] * (n + 1)
    coin = []
    i = 1
    while i <= n:
        coin.append(i)
        i *= 2
    dp[0] = 1
    for j in range(len(coin)):
        for i in range(1, n + 1):
            if i >= coin[j]:
                dp[i] += dp[i - coin[j]]
                dp[i] %= 1000000000

    print(dp[n])
