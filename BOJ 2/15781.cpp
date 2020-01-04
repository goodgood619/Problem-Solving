#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n,m,a=0,b=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        Int num;
        scanf("%d",&num);
        a = max(a,num);
    }
    for(int i=0;i<m;i++) {
        Int num;
        scanf("%d",&num);
        b = max(b,num);
    }
    printf("%d\n",a+b);
    return 0;
}