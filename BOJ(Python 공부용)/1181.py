import sys

sys.setrecursionlimit(50000000)

n = int(sys.stdin.readline())
v = []
for i in range(n):
    word = sys.stdin.readline()
    length = len(word)
    v.append((word, length))

v = list(set(v))

v.sort(key=lambda x: (x[1], x[0]))

for i in v:
    print(i[0].strip("\n"))
