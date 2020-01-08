#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int t;
    scanf("%d",&t);
    while(t--) {
        //ABCDEFGHIJKL
        Int a,b;
        scanf("%d%d",&a,&b);
        if(a<12 || b<4) printf("-1\n");
        else {
            printf("%d\n",11*b + 4);
        }
    }
    return 0;
}