import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    n *= 2
    arr = [0] * 100000
    cur, Max = 0, 0
    temp = [int(x) for x in input.readline().split()]
    for i in range(n):
        num = temp[i]
        num -= 1
        if arr[num] == 0:
            cur += 1
        elif arr[num] == 1:
            cur -= 1
        arr[num] += 1
        Max = max(Max, cur)

    print(Max)
