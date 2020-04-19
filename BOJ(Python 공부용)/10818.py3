n = input()
n = int(n)

v = list(map(int,input().split()))
v.sort()
len = v.__len__()
print("%d %d" %(v[0],v[len - 1])) 