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
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int dp[1 << 17];
int n, p;
int board[17][17];
string s;
int go(int via, int cnt) {
	if (cnt >= p) {
		return 0;
	}
	int &ret = dp[via];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < n; i++) {
		if (via & (1 << i)) {
			for (int j = 0; j < n; j++) {
				if (!(via & (1 << j)))
					ret = min(ret, go(via | (1 << j), cnt + 1) + board[i][j]);
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i <n; i++) {
		for (int j = 0; j <n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	cin >> s;
	scanf("%d", &p);
	int ok = 0;
	int via = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'Y') {
			via |= (1 << i);
			ok++;
		}
	}
	int ans = 1e9;
	if (ok >= p) {
		printf("0\n");
	}
	else if (ok == 0) printf("-1\n");
	else {
		ans = min(ans, go(via, ok));
		printf("%d\n", ans);
	}
	return 0;

}