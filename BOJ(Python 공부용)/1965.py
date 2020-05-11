import sys
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    arr = [int(x) for x in input.readline().split()]
    dp = [-1] * n
    Max = 1
    for i in range(n):
        dp[i] = 1
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] + 1)
                Max = max(Max, dp[i])

    print(Max)
