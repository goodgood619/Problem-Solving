import sys

input = sys.stdin


def go(h, w):
    return (h[0] + w[0]) * (100 + h[1] + w[1]) * (
            100 * (100 - min(h[2] + w[2], 100)) + min(h[2] + w[2], 100) * (h[3] + w[3])) * (100 + h[4] + w[4])


if __name__ == '__main__':
    a = [int(x) for x in input.readline().split()]
    b = [int(x) for x in input.readline().split()]
    a1 = [int(x) for x in input.readline().split()]
    b1 = [int(x) for x in input.readline().split()]

    for i in range(5):
        a[i] -= a1[i]
        b[i] -= b1[i]

    dif1 = go(a, b1) - go(a, a1)
    dif2 = go(b, a1) - go(b, b1)

    if dif1 > 0:
        print('+')
    elif dif1 == 0:
        print('0')
    else:
        print('-')

    if dif2 > 0:
        print('+')
    elif dif2 == 0:
        print('0')
    else:
        print('-')
