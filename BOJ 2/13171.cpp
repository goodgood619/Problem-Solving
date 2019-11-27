#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[8] = {0,0,-1,1,1,1,-1,-1};
int goy[8] = {1,-1,0,0,-1,1,-1,1};
#define mod 1000000007
int main() {
    ll a,x,ans = 1;
    scanf("%lld%lld",&a,&x);
    a%=mod;
    while(x){
        if(x%2==1){
            ans = (ans*a)%mod;
        }
        a = (a*a)%mod;
        x/=2;
    }
    printf("%lld\n",ans);
    return 0;
}