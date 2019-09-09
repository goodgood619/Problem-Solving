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
int n, m,st,en;
vector<vector<P>> a,b;
int dist[505];
void dijk(int st) {
	for (int i = 0; i <= n; i++)  dist[i] = 1e9;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,st });
	dist[st] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (cost > dist[here]) continue;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (nextcost == -1) continue;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
			}
		}
	}

}
void dfs(int en) {
	for (int i = 0; i < b[en].size(); i++) {
		int back = b[en][i].first;
		int backcost = b[en][i].second;
		if (dist[back] + backcost == dist[en]) {
			for (int j = 0; j < a[back].size(); j++) {
				int next = a[back][j].first;
				if (next == en) {
					a[back][j].second = -1;
					dfs(back);
				}
			}
		}
	}
}
int main(void) {
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		scanf("%d%d", &st, &en);
		a.clear();
		b.clear();
		a.resize(n + 1);
		b.resize(n + 1);
		memset(dist, 0, sizeof(dist));
		for (int i = 1; i <= m; i++) {
			int left, right,cost;
			scanf("%d%d%d", &left, &right,&cost);
			a[left].push_back({ right,cost });
			b[right].push_back({ left,cost });
		}
		dijk(st);
		dfs(en);
		dijk(st);
		dist[en] == 1e9 ? printf("-1\n") : printf("%d\n", dist[en]);
	}
	return 0;
}