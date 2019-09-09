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
int dist[505];
vector <vector<pair<int, int>>> a;
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
	}
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	dist[1] = 0;
	bool cycle = false;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int next = a[i][j].first;
				int nextcost = a[i][j].second;
				if (dist[next] > dist[i] + nextcost && dist[i]!=1e9) {
					dist[next] = dist[i] + nextcost;
					if (k == n) cycle = true;
				}
			}
		}
	}

	if (cycle) printf("-1\n");
	else {
		for (int i = 2; i <= n; i++) {
			dist[i] == 1e9 ? printf("-1\n") : printf("%d\n", dist[i]);
		}
	}
	return 0;
}