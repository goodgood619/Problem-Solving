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
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m,k,cycle;
vector<vector<int>> a;
vector<int> v;
int indegree[10005];
int make[10005];
int dp[10005];
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &make[i]);
		int cnt;
		scanf("%d", &cnt);
		for (int j = 1; j <= cnt; j++) {
			int pre;
			scanf("%d", &pre);
			a[pre].push_back(i);
			indegree[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			dp[i] = make[i];
		}
	}
	int Max = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
			}
			dp[next] = max(dp[next], dp[here] + make[next]);
		}
	}
	for (int i = 1; i <= n; i++) {
		Max = max(Max, dp[i]);
	}
	printf("%d\n", Max);
	return 0;
}