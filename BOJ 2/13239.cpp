#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
ll go(int n,int k,ll** &dp) {
    if(n<=0 || n<k) return 0;
    if(k ==0 || k == n) return 1;
    ll &ret = dp[n][k];
    if(ret!=-1) return ret;
    ret = 0;
    ret = go(n-1,k-1,dp) + go(n-1,k,dp);
    ret %= 1000000007;
    return ret;
}
int main() {
    ll **dp = new ll*[1001];
    for(int i=0;i<=1000;i++) dp[i] = new ll[1001];
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            dp[i][j] = -1;
        }
    }
    Int t;
    scanf("%d",&t);
    while(t--) {
        Int n,k;
        scanf("%d%d",&n,&k);
        printf("%lld\n",go(n,k,dp));
    }
    for(int i=0;i<=1000;i++) delete[] dp[i];
    delete dp;
    return 0;
}