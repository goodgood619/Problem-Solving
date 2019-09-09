#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <deque>
using namespace std;
int n, m;
vector<vector<int>> a;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int make[1001] = { 0, };
		int indegree[1001] = { 0, };
		int dp[1001] = { 0, };
		int w;
		queue<int> q;
		a.clear();
		a.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &make[i]);
		}
		for (int i = 1; i <= m; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back(second);
			indegree[second]++;
		}
		scanf("%d", &w);
		for (int i = 1; i <= n; i++) {
			if (!indegree[i]) {
				q.push(i);
				dp[i] = make[i];
			}
		}
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
		printf("%d\n", dp[w]);
	}
	return 0;
}