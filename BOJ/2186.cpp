#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
using namespace std;
typedef long long ll;
#define INF 1e9
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int n, m, k, ans;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
char board[105][105];
int dp[105][105][105]; // x,y,cnt
string s;
queue<PPP> q;
int dfs(int x, int y, int cnt){
	if (cnt == s.size()) {
		return 1;
	}
	int &ret = dp[x][y][cnt];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = x + i * gox[j];
			int ny = y + i * goy[j];
			if (nx<1 || nx>n || ny<1 || ny>m) continue;
			if (board[nx][ny] == s[cnt]){
				ret+=dfs(nx, ny, cnt + 1);
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}
	cin >> s;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == s[0]){
				ans+=dfs(i, j, 1);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}