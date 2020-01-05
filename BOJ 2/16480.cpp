#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    // d^2 = R(R-2r)
    ll R,r;
    scanf("%lld%lld",&R,&r);
    printf("%lld\n",R*(R-2*r));
    return 0;
}