import sys

input = sys.stdin
sys.setrecursionlimit(5000)

n, m, k = map(int, input.readline().split())
board = [[0] * m for _ in range(n)]
sticker = []


def first(sticker, r, c):
    ex = n - r
    ey = m - c
    if ex < 0 or ey < 0: return False
    x = 0
    y = 0
    ok = False
    while True:
        p = x
        q = y
        no = False
        for i, a in zip(range(r), range(p, p + r, 1)):
            for j, b in zip(range(c), range(q, q + c, 1)):
                if board[a][b] == 1 and sticker[i][j] == 1:
                    no = True
        if not no:
            for i, a in zip(range(x, x + r, 1), range(0, r, 1)):
                for j, b in zip(range(y, y + c, 1), range(0, c, 1)):
                    if sticker[a][b] == 1 and board[i][j] == 0:
                        board[i][j] = sticker[a][b]
            ok = True
        if y == ey:
            y = 0
            x += 1
        else:
            y += 1
        if x > ex or ok:
            break
    return ok


for _ in range(k):
    r, c = map(int, input.readline().split())
    temp = [[int(x) for x in input.readline().split()] for _ in range(r)]

    sticker.append(temp)

for e in sticker:
    r = len(e)
    c = len(e[0])
    # 1번
    if first(e, r, c):
        continue

    # 2번
    for i in range(3):
        temp = [[]]
        if i == 0:
            temp = [[0] * r for _ in range(c)]
            for a, q in zip(range(c), range(0, c, 1)):
                for b, p in zip(range(r), range(r - 1, -1, -1)):
                    temp[a][b] = e[p][q]

            if first(temp, c, r):
                break
        if i == 1:
            temp = [[0] * c for _ in range(r)]
            for a, p in zip(range(r), range(r - 1, -1, -1)):
                for b, q in zip(range(c), range(c - 1, -1, -1)):
                    temp[a][b] = e[p][q]

            if first(temp, r, c):
                break
        if i == 2:
            temp = [[0] * r for _ in range(c)]
            for a, q in zip(range(c), range(c - 1, -1, -1)):
                for b, p in zip(range(r), range(0, r, 1)):
                    temp[a][b] = e[p][q]
            if first(temp, c, r):
                break

cnt = 0
for i in range(n):
    for j in range(m):
        if board[i][j] == 1:
            cnt += 1

print(cnt)