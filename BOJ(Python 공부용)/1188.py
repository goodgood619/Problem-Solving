import sys

input = sys.stdin
sys.setrecursionlimit(100)


def gcd(a, b):
    if a % b == 0: return b
    return gcd(b % a, a)


x, y = map(int, input.readline().split())
res = gcd(x, y)
print(y - res)
