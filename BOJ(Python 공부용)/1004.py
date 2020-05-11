import sys

input = sys.stdin

if __name__ == '__main__':
    t = int(input.readline())
    for _ in range(t):
        sx, sy, ex, ey = map(int, input.readline().split())
        ans = 0
        n = int(input.readline())
        for i in range(n):
            x, y, r = map(int, input.readline().split())
            dist1 = (x - sx) * (x - sx) + (y - sy) * (y - sy)
            dist2 = (x - ex) * (x - ex) + (y - ey) * (y - ey)
            dist3 = r * r
            if (dist1 - dist3) * (dist2 - dist3) <= 0: ans += 1
        print(ans)
