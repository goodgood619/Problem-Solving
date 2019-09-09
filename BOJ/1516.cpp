#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <functional>
using namespace std;
int n;
vector<vector<int>> a;
int indegree[501];
int make[501];
int dp[501];
queue<int> q;
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int ti;
		scanf("%d", &ti);
		make[i] = ti;
		while (1) {
			int first;
			scanf("%d", &first);
			if (first == -1) break;
			a[first].push_back(i);
			indegree[i]++;
		}
	}
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
			if (indegree[next] == 0) q.push(next);
			dp[next] = max(dp[next], dp[here] + make[next]);
		}
	}

	for (int i = 1; i <= n; i++) printf("%d\n", dp[i]);
	return 0;
}