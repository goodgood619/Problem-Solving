import sys

input = sys.stdin
sys.setrecursionlimit(100000)


def update(index, value, h):
    index += (h - 1)
    seg[index] += value
    while index > 1:
        index //= 2
        seg[index] = seg[index * 2] + seg[index * 2 + 1]


def query(nodenum, left, right, nodeleft, noderight):
    if left > noderight or nodeleft > right:
        return 0
    elif left <= nodeleft and noderight <= right:
        return seg[nodenum]
    mid = (nodeleft + noderight) // 2
    return query(nodenum * 2, left, right, nodeleft, mid) + query(nodenum * 2 + 1, left, right, mid + 1, noderight)


if __name__ == '__main__':
    n, q = map(int, input.readline().split())
    h = 1
    while h < n:
        h <<= 1
    seg = [0] * (2 * h)
    for i in range(q):
        choice, left, right = map(int, input.readline().split())
        if choice == 1:
            update(left, right, h)
        else:
            print(query(1, left, right, 1, h))
