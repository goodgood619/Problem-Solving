#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
 
#define INF 1e9+7
#define ull unsigned long long
 
using namespace std;
int t, n, m, l, g;
int goR[110][110], goD[110][110], dp[110][110][210][2];
int DP(int cY, int cX, int cT, int cL) {
    if (cT < 0)    return INF;
    if (cY == n - 1 && cX == m - 1 && cT == 0)    return 0;
 
    int& ret = dp[cY][cX][cT][cL];
    if (ret != -1)    return ret;
 
    ret = INF;
 
    if (cY + 1 < n) {
        if (cL == 0)    ret = min(ret, DP(cY + 1, cX, cT, 0) + goD[cY][cX]);
        else ret = min(ret, DP(cY + 1, cX, cT - 1, 0) + goD[cY][cX]);
    }
    if (cX + 1 < m) {
        if (cL == 0)    ret = min(ret, DP(cY, cX + 1, cT - 1, 1) + goR[cY][cX]);
        else ret = min(ret, DP(cY, cX+1, cT, 1) + goR[cY][cX]);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m >> l >> g;
        for (int i = 0; i < n; i++)    for (int j = 0; j < m - 1; j++)    cin >> goR[i][j];
        for (int i = 0; i < n - 1; i++)    for (int j = 0; j < m; j++)    cin >> goD[i][j];
        for (int i = 0; i < n; i++)    for (int j = 0; j < m; j++)    for (int k = 0; k < 210; k++)    for (int l = 0; l < 2; l++)    dp[i][j][k][l] = -1;
        bool isGo = 0;
        for (int i = 0; i < n + m && !isGo; i++) {
            int ret = min(DP(0, 0, i, 0), DP(0, 0, i, 1));
            if (ret <= g) {
                cout << i + (m + n - 2) * l<<'\n';
                isGo = 1;
            }
        }
        if (!isGo)    cout << -1 << '\n';
    }
}
