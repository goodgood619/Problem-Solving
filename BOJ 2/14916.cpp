#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int go(int k,int *dp, vector<int> &coin) {
    if(k<0) return 1e9;
    if(k==0) return 0;
    int &ret = dp[k];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int i=0;i<coin.size();i++){
        if(k-coin[i]>=0) ret = min(ret,go(k-coin[i],dp,coin)+1);
    }
    return ret;
}
int main() {
    int n;
    scanf("%d",&n);
    vector<int> coin;
    coin.push_back(2),coin.push_back(5);
    int *dp = new int[n+1];
    for(int i=1;i<=n;i++) dp[i] = -1;
    int ans = go(n,dp,coin);
    ans == 1e9 ? printf("-1\n") : printf("%d\n",ans);
    delete[] dp;
    coin.clear();
    return 0;
}