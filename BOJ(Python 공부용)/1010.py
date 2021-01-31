import sys
from math import factorial
t = int(input())
for i in range(t):
    m, n = map(int, sys.stdin.readline().split())
    ans = factorial(n) // (factorial(n-m)*factorial(m))
    print(ans)