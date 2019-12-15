#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    while(true) {
        ll a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a == 0 && b==0 && c==0 && d==0) break;
        if(a == 0) {
            a = d/c/b;
            printf("%lld %lld %lld %lld\n",a,b,c,d);
        }
        else if(b == 0 ){
            b = d/c/a;
            printf("%lld %lld %lld %lld\n",a,b,c,d);
        }
        else if(c == 0){
            c = d/a/b;
            printf("%lld %lld %lld %lld\n",a,b,c,d);
        }
        else {
            d = a*b*c;
            printf("%lld %lld %lld %lld\n",a,b,c,d);
        }
    }
    return 0;
}