import sys

input = sys.stdin

if __name__ == '__main__':
    for _ in range(3):
        n = int(input.readline())
        sum = 0
        for _ in range(n):
            sum += int(input.readline())

        if sum == 0:
            print("0")
        elif sum > 0:
            print("+")
        else:
            print("-")
