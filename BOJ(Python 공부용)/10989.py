import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    dp = [0] * 10001
    for _ in range(n):
        dp[int(input.readline())] += 1

    for i in range(1, 10001):
        if dp[i] == 0: continue
        while dp[i] > 0:
            print(i)
            dp[i] -= 1
