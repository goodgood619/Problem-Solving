import sys

input = sys.stdin

if __name__ == '__main__':
    n = int(input.readline())
    arr = [0] * n
    for i in range(n):
        arr[i] = int(input.readline())

    arr.sort()
    for i in range(len(arr) - 1, 1, -1):
        if arr[i] < arr[i - 1] + arr[i - 2]:
            print(arr[i] + arr[i - 1] + arr[i - 2])
            sys.exit(0)

    print(-1)
