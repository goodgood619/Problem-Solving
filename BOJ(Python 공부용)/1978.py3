n = input()
n = int(n)
v = list(map(int,input().split()))

cnt = 0

for i in v:
    check = True
    for j in range(2,i,1):
        if i%j == 0 :
            check = False
            break
    if check == True and i!=1: 
        cnt+=1

print(cnt)