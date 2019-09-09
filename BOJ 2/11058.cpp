#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long dp[101];
int main() {
int n;
    scanf("%d",&n);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;
    for (int i = 7; i <= 100; i++) {
        for (int j = 1; j <= i-3; j++) {
            dp[i] = max(max(dp[i - 1] + 1, (dp[i - (j+2)] * (j + 1))), dp[i]);
        }
    }
    printf("%lld\n",dp[n]);
}