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
int t, Case = 1,n,m;
int ladder[101], snakes[101],dp[101];
int bfs(int st,int c) {
	queue<pair<int, int>> q;
	q.push({ st,c });
	dp[st] = 0;
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (ladder[here] != 0) {
			int next = ladder[here];
			q.push({ next,cnt });
			continue;
		}
		if (snakes[here] != 0) {
			int next = snakes[here];
			q.push({ next,cnt });
			continue;
		}
		for (int i = 1; i <= 6; i++) {
			int next = here + i;
			if (next > 100)continue;
			if (dp[next] > cnt + 1) {
				dp[next] = cnt + 1;
				q.push({ next,cnt + 1 });
			}
		}
	}
	return dp[100];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ladder[x] = y;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		snakes[x] = y;
	}
	for (int i = 1; i <= 100; i++) dp[i] = 1e9;
	printf("%d\n", bfs(1, 0));
	return 0;
}