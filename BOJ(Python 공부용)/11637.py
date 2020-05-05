import sys
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    t = int(input.readline())
    for _ in range(t):
        n = int(input.readline())
        v = []
        for _ in range(n):
            v.append(int(input.readline()))
        total, Max, idx = 0, 0, -1
        map = {}
        for i in range(len(v)):
            total += v[i]
            if Max < v[i]:
                Max = v[i]
                idx = i
        no = False
        for i in range(len(v)):
            if Max == v[i] and idx != i:
                no = True
                break
        if no:
            print("no winner")
            continue

        ret = Max / total
        if ret > 0.5:
            print("majority winner", (idx + 1))
        else:
            print("minority winner", (idx + 1))
