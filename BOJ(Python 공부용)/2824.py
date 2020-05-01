import sys

input = sys.stdin
sys.setrecursionlimit(100000)

def gcd(a, b):
    if a % b == 0: return b
    return gcd(b % a, a)


if __name__ == '__main__':
    n = int(input.readline())
    a = [int(x) for x in input.readline().split()]
    m = int(input.readline())
    b = [int(x) for x in input.readline().split()]
    A, B = a[0], b[0]
    for i in range(1, n):
        A *= a[i]
    for i in range(1, m):
        B *= b[i]

    res = gcd(A, B)
    ans = []
    p = res
    while p > 0:
        ans.append(p % 10)
        p //= 10
    ans.reverse()
    if len(ans) >= 10:
        for i in range(len(ans) - 9, len(ans)):
            print(ans[i], end="")
    else:
        print(res)
