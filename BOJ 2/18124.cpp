#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
int main() {
    ll k = 1,n;
    scanf("%lld",&n);
    while(k<n) k*=2;
    printf("%lld\n",k-1-(k-n)/2);
    return 0;
}