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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int arr[2005];
int dp[2005][2005];

int go(int s, int e) {
	if (s >= e) return 1;
	if (arr[s] != arr[e]) return 0;
	int &ret = dp[s][e];
	if (ret != -1) return ret;
	ret = go(s + 1, e - 1);
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &arr[i]);
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			go(i, j);
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		printf("%d\n", go(left, right));
	}
	return 0;
}