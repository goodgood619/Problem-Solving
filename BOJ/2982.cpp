#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <map>
using namespace std;
typedef pair<int, int> P;
vector<vector<P>> a;
priority_queue<P, vector<P>, greater<P>> pq;
int n, m, start, en, k, godula, first, second;
int maxgo[1005][1005];
int minmin[1005][1005];
int maxmax[1005][1005];
int gogo[1005];
int dist[1005];
int total;
#define INF 2000000000
void dijk(int start) {
	dist[start] = k;
	pq.push({ k,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (dist[vertex] < cost) continue;
		for (int i = 0; i < a[vertex].size(); i++) {
			total = 0;
			int next = a[vertex][i].first;
			int nextcost = a[vertex][i].second;
			int nextfirst = minmin[vertex][next];
			int nextsecond = maxmax[vertex][next];
			if (cost >= nextfirst && cost <= nextsecond) total += nextsecond - cost;
			if (dist[next] > dist[vertex] + nextcost + total) {
				dist[next] = dist[vertex] + nextcost + total;
				pq.push({ dist[next],next });
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	scanf("%d%d%d%d", &start, &en, &k, &godula);
	for (int i = 1; i <= godula; i++) {
		scanf("%d", &gogo[i]);
	}
	for (int i = 1; i <= m; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
		maxgo[first][second] = cost;
		maxgo[second][first] = cost;
	}
	int now = 0;
	for (int i = 1; i <= godula - 1; i++) {
		int first = gogo[i];
		int second = gogo[i + 1];
		int cost = maxgo[gogo[i]][gogo[i + 1]];
		int temp = now;
		now += cost;
		minmin[first][second] = temp;
		minmin[second][first] = temp;
		maxmax[first][second] = now;
		maxmax[second][first] = now;
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dijk(start);
	printf("%d\n", dist[en] - k);
	return 0;
}