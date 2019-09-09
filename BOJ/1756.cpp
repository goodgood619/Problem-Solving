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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
int oven[300001], pizza[300001], dp[300001];
typedef unsigned long long lll;
int main() {
	setbuf(stdout, NULL);
	int d, n;
	scanf("%d%d", &d, &n);
	for (int i = 1; i <= 300000; i++) dp[i] = 1e9 + 5;
	for (int i = 1; i <= d; i++) scanf("%d", &oven[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &pizza[i]);
	for (int i = 1; i <= d; i++) {
		if (i == 1) dp[i] = oven[i];
		else dp[i] = min(dp[i - 1], oven[i]);
	}
	int idx = 1,ans=0;
	for (int i = d; i >=1 && idx<=n; i--) {
		if (dp[i] >= pizza[idx]) {
			ans = i;
			idx++;
		}
	}
	idx != n + 1 ? printf("0\n") : printf("%d\n", ans);
	return 0;
}