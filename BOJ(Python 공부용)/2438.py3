t = input()
t = int(t)

for i in range(1,t+1,1):
    for j in range(i):
        print("*",end='')
    print("")        