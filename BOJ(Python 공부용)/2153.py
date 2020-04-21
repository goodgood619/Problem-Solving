import sys

input = sys.stdin
sys.setrecursionlimit(100)

s = input.readline().strip("\n")


def check(num):
    if num == 1:
        return True
    for i in range(2, num):
        if num % i == 0:
            return False

    return True


cnt = 0
for i in range(len(s)):
    if s[i].islower() == True:
        cnt += ord(s[i]) - 96
    else:
        cnt += ord(s[i]) - 38

res = check(cnt)
if res:
    print("It is a prime word.")
else:
    print("It is not a prime word.")
