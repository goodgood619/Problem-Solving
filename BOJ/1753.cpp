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
#define mod 1000000009
#define lim 1000000000
typedef pair < int,int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {-1,0,1,0 };
int goy[4] = {0,1,0,-1 };
int n, m, st;
vector<vector<P>> a;
int dist[20005];
void dijk(int st) {
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	dist[st] = 0;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (cost > dist[here]) continue;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
			}
		}
	}
	
}
int main(void) {
	scanf("%d%d%d", &n, &m, &st);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int left, right, cost;
		scanf("%d%d%d", &left, &right, &cost);
		a[left].push_back({ right,cost });
	}

	dijk(st);
	for (int i = 1; i <= n; i++) {
		int ans = dist[i];
		ans == 1e9 ? printf("INF\n") : printf("%d\n", ans);
	}
	return 0;
}