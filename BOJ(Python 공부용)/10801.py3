a = input().split()
b = input().split()

cnt =0
for i in range(10):
    a[i] = int(a[i])
    b[i] = int(b[i])

    if a[i]>b[i]:
        cnt +=1
    elif a[i]<b[i]:
        cnt-=1

if cnt>0:
    print('A')
elif cnt ==0:
    print('D')
else:
    print('B')