import sys

input = sys.stdin

if __name__ == '__main__':
    k, n = map(int, input.readline().split())
    v = []
    left, right = 1, 0
    for i in range(k):
        v.append(int(input.readline()))
        right = max(right, v[i])

    while left <= right:
        mid = (left + right) // 2
        cnt = 0
        for i in range(len(v)):
            cnt += (v[i] // mid)
        if cnt < n:
            right = mid - 1
        else:
            left = mid + 1
    left -= 1
    print(left)
