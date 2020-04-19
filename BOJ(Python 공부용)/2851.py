import sys

sys.setrecursionlimit(50000000)

arr = [0] * 10
v = [0]*10
sum = 0
for i in range(10):
    arr[i] = int(sys.stdin.readline())
    sum += arr[i]
    v.append(sum)

v.sort()
min = int(1e9)
num = 0

for i in range(len(v)):
    if min > abs(100 - v[i]):
        min = abs(100 - v[i])
        num = v[i]
    elif min == abs(v[i] - 100):
        num = max(num, v[i])

print(num)
