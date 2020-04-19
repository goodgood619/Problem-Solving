n = int(input())

v = []
for i in range(n):
    s = input()
    length = len(s)
    v.append((s,length))

v = list(set(v))
v = sorted(v,key=lambda x: (x[1],x[0]))

for i in v:
    print("%s" %(i[0]))