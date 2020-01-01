#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
double dp[7][7][7][1001];
int money(int i,int j,int k) {
    if (i == j && j == k) return 10000 + i * 1000;
    if (i == j) return 1000 + i * 100;
    if (k == j) return 1000 + k * 100;
    if (i == k) return 1000 + i * 100;
    return max(max(i, j), k) * 100;
}
double dfs(int i,int j,int k,int turn) {
    if(turn<0) return 0;
    double &ret = dp[i][j][k][turn];
    if(ret != -1) return ret;
    ret = 0;
    double cur = money(i,j,k);
    for(int r=1;r<=6;r++) {
        ret += dfs(j,k,r,turn-1);
    }
    ret = max(ret,cur);
    ret /= 6;
    return ret;
}
int main() {
    Int n;
    scanf("%d",&n);
    for(int i=0;i<=6;i++) {
        for(int j=0;j<=6;j++) {
            for(int k=0;k<=6;k++) {
                for(int p=0;p<=1000;p++){
                    dp[i][j][k][p] = -1;
                 }
            }
        }
    }
    double ans = 0;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++) {
            for(int k=1;k<=6;k++){
                dfs(i,j,k,n-3);
            }
        }
    }
    for(int i=1;i<=6;i++) {
        for(int j=1;j<=6;j++) {
            for(int k=1;k<=6;k++) {
                ans += (1.0)/36 * dp[i][j][k][n-3];
            }
        }
    }
    printf("%.8lf\n",ans);
    return 0;
}