import sys
from math import factorial
n, m = map(int, sys.stdin.readline().split())
ans = factorial(n) // (factorial(n-m)*factorial(m))
print(ans)
