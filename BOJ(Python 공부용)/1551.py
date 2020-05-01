import sys
from math import sqrt

input = sys.stdin

if __name__ == '__main__':
    n, k = map(int, input.readline().split())
    v = [int(x) for x in input.readline().split(",")]

    for i in range(k):
        temp = []
        for j in range(len(v)):
            if j == len(v) - 1: break
            temp.append(v[j + 1] - v[j])

        v = temp

    for i in range(len(v)):
        if i == len(v) - 1:
            print(v[i], end="\n")
        else:
            print(v[i], end=",")
