import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    v = []
    for _ in range(n):
        f, s = map(int, input.readline().split())
        v.append((f, s))

    v.sort()
    first, second = v[0][0], v[0][1]
    sum = second - first
    for i in range(1, n):
        nextfirst, nextsecond = v[i][0], v[i][1]
        if first <= nextfirst <= second <= nextsecond:
            sum += (nextsecond - second)
            second = nextsecond
        elif nextfirst > second:
            first = nextfirst
            second = nextsecond
            sum += (second - first)

    print(sum)