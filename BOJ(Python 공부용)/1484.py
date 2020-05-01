import sys
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    v = []
    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            if i == n // i:
                v.append(i)
            else:
                v.append(i)
                v.append(n // i)

    v.sort()
    ans = []
    for i, j in zip(range(0, len(v)), range(len(v) - 1, -1, -1)):
        if i > j: break
        a = (v[j] + v[i]) / 2
        b = (v[j] - v[i]) / 2
        if a != int(a) or b != int(b) or b <= 0: continue
        ans.append(int(a))

    if len(ans) == 0:
        print("-1")
    else:
        ans.sort()
        for i in range(len(ans)):
            print(ans[i], end="\n")
