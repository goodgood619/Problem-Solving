import sys

input = sys.stdin
sys.setrecursionlimit(500000)

n = int(input.readline())
v = [int(x) for x in input.readline().split()]
plus, minus, multiply, divide = map(int, input.readline().split())
Max = int(-2e9)
Min = int(2e9)


def go(sum, index, depth, plus, minus, multi, divi):
    global Max, Min
    if plus == 0 and minus == 0 and multi == 0 and divi == 0:
        Max = max(Max, sum)
        Min = min(Min, sum)
        return

    if plus != 0:
        go(sum + v[index], index + 1, depth, plus - 1, minus, multi, divi)
    if minus != 0:
        go(sum - v[index], index + 1, depth, plus, minus - 1, multi, divi)
    if multi != 0:
        go(sum * v[index], index + 1, depth, plus, minus, multi - 1, divi)
    if divi != 0:
        go(int(sum / v[index]), index + 1, depth, plus, minus, multi, divi - 1)


go(v[0], 1, n, plus, minus, multiply, divide)
print("%d\n%d" % (Max, Min))