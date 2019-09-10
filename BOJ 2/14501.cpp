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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m,ans;
P arr[16];
bool visited[16];
void dfs(int curday,int sum) {
	if (curday > n) {
		if (curday == n + 1) ans = max(ans, sum);
		return;
	}
	ans = max(ans, sum);
	if (curday + arr[curday - 1].first <= n+1) {
		dfs(curday + arr[curday - 1].first, sum + arr[curday - 1].second);
	}
	else {
		dfs(curday + 1, sum);
	}
	dfs(curday + 1, sum);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int day, pay;
		scanf("%d%d", &day, &pay);
		arr[i] = { day,pay };
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}