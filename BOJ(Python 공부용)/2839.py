import sys
n =int(sys.stdin.readline())
ans = 99999
for i in range(0,n+1,3):
    for j in range(0,n+1,5):
        if(i+j== n):
            ans = min(ans,i//3+j//5)

if ans == 99999:
    print(-1)
else:
    print(ans)