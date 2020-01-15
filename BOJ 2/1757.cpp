#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdint>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int dp[10000][501];
int go(int n, int k,int depth,int m,int* &run) {
    if (n > depth) return -1e9;
     if (n == depth) {
        if (k == 0) return 0;
        else return -1e9;
    }
    int& ret = dp[n][k];
    if (ret != -1) return ret;
    ret = 0;
    // 무조건 못뜀
    if (depth - n <= k + 1) {
        return ret = max(ret, go(n + k, 0, depth, m,run));

    }
    //그 전상태까지 쉬는중
    if (k == 0) {
        ret = max(ret, max(go(n + 1, k + 1, depth, m,run) + run[n], go(n + 1, 0, depth, m,run)));
    }
    else {
        if (k + 1 <= m) ret = max(ret, max(go(n + 1, k + 1, depth, m,run) + run[n], go(n + k, 0, depth, m,run)));
        else ret = max(ret, go(n + k, 0, depth, m,run));
    }
    return ret;
}
int main() {
    Int n, m;
    scanf("%d%d", &n, &m);
    Int* run = new int[n];
    for (int i = 0; i < n; i++) run[i] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &run[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", go(0, 0,n,m,run));
    delete[] run;
    return 0;
}