import sys
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    a = int(input.readline())
    t = int(input.readline())
    choice = int(input.readline())

    cur, idx, n = 0, -1, 1
    burn, dagie = 0, 0

    while True:
        if cur == 0:
            burn += 1
        elif cur == 1:
            dagie += 1
        elif cur == 2:
            burn += 1
        elif cur == 3:
            dagie += 1
        elif cur == 4:
            for _ in range(n + 1):
                burn += 1
                idx = (idx + 1) % a
                if choice == 0 and burn == t:
                    print(idx)
                    sys.exit(0)
            cur += 1
            continue
        else:
            for _ in range(n + 1):
                dagie += 1
                idx = (idx + 1) % a
                if choice == 1 and dagie == t:
                    print(idx)
                    sys.exit(0)
            n += 1
            cur = 0
            continue
        idx = (idx + 1) % a
        cur += 1
        if choice == 1 and dagie == t: break
        if choice == 0 and burn == t: break
    print(idx)
