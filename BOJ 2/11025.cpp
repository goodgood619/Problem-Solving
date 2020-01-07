#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n,k,r=1;
    scanf("%d%d",&n,&k);
    for(Int i=2;i<=n;i++) {
        r = (r + k-1)%i + 1;
    }
    printf("%d\n",r);
    return 0;
}