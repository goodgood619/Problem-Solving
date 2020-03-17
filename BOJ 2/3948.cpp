#include<stdio.h>
#include<algorithm>
#include <cstring>
#include<iostream>
using namespace std;
typedef long long ll;
ll t, n, ans, dp[21][21][2], chk[21];// 현재숫자 몇번째숫자
ll go(ll depth, ll now, ll size)
{
    if (depth == n)
        return 1;
    ll& ret = dp[depth][now][size];
    if (ret != -1) return ret;
    ret = 0;
    if (size == 0)
        for (int i = now + 1; i <= n; i++)
            if (chk[i] == 0)
                chk[i] = 1, ret += go(depth + 1, i, 1),chk[i]=0;
    if (size == 1)
        for (int i = now - 1; i >= 1; i--)
            if (chk[i] == 0) {
            chk[i] = 1, ret += go(depth + 1, i, 0);
            chk[i] = 0;
                }
    return ret;
}
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        ans = 0;
        scanf("%lld", &n);
        memset(dp, -1, sizeof(dp));
        memset(chk, 0, sizeof(chk));
        if (n == 1)
        {
            printf("1\n");
            continue;
        }
        for (ll i = 1; i <= n; i++)
        {
            chk[i] = 1;
            ans += go(1, i, 0);
            chk[i] = 0;
            chk[i] = 1;
            ans += go(1, i, 1);
            chk[i] = 0;
        }
        printf("%lld\n", ans);
    }
    return 0;
}