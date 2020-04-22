import sys

input = sys.stdin
sys.setrecursionlimit(100)

n = input.readline().strip("\n")
ok = False
cnt = 0
while len(n) >= 2:
    sum = 0
    p = n
    for i in n:
        sum += int(i)
    cnt += 1
    n = str(sum)

if int(n) % 3 == 0:
    print(cnt, "\nYES")
else:
    print(cnt, "\nNO")