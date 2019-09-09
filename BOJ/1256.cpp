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
#define mod 1000000007
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, k;
int dp[205][205];
void go(int n, int m, int total,ll k, string s) {
	if (n == 0) {
		for (int i = 1; i <= total; i++) {
			s.push_back('z');
		}
		printf("%s\n", s.c_str());
		exit(0);
	}
	int ret = dp[total-1][n - 1];
	if (k >ret) {
		go(n, m - 1, total - 1, k - ret, s + "z");
	}
	else {
		go(n - 1, m, total - 1, k, s + "a");
	}
}
int main() {
	for (int i = 0; i <= 200; i++) dp[i][0] = 1;
	for (int i = 0; i <= 200; i++) dp[i][i] = 1;
	for (int i = 2; i <= 200; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			if (dp[i][j] > 1e9) {
				dp[i][j] = 1e9 + 5;
			}
		}
	}
	scanf("%d%d%d", &n, &m, &k);
	if (dp[n + m][n] < k) {
		printf("-1\n");
		return 0;
	}
	go(n, m, n + m,k, "");
	return 0;
}