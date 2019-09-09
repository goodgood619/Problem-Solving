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
typedef long long ll;
ll dist[101];
ll money[101];
int cy[101];
bool visited[101];
int n, st, en, m;
vector<vector<pair<int, ll>>> a;
queue<int> q;
int bfs() {
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == en) return 1;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d%d%d%d", &n, &st, &en, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		ll cost;
		scanf("%d%d%lld", &first, &second, &cost);
		a[first].push_back({ second,cost });
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &money[i]);
		money[i] = -money[i];
	}
	bool cycle = false;
	for (int i = 0; i < n; i++) dist[i] = 1e14;
	dist[st] = money[st];
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int next = a[i][j].first;
				int nextcost = a[i][j].second;
				if (dist[next] > dist[i] + nextcost+money[next] && dist[i] != 1e14) {
					dist[next] = dist[i] + nextcost + money[next];
					if (k == n) {
						q.push(next);
						visited[next] = true;
						cycle = true;
					}
				}
			}
		}
	}

	if (cycle) {
		if (dist[en] == 1e14) printf("gg\n");
		else if (bfs()) printf("Gee\n");
		else printf("%lld\n", -dist[en]);
	}
	else {
		if (dist[en] != 1e14) printf("%lld\n", -dist[en]);
		else printf("gg\n");
	}
	return 0;
}