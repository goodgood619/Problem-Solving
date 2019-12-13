#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n,m;
    scanf("%d%d",&n,&m);
    Int rest = m;
    Int Max = m;
    for(int i=0;i<n;i++) {
        Int in,out;
        scanf("%d%d",&in,&out);
        rest += in, rest -= out;
        if(rest>=0 ) {
            Max = max(Max, rest);
        } else {
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n",Max);
    return 0;
}