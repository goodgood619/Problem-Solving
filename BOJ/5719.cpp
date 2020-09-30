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
typedef pair < int, int > P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int n, m, st, en;
int a[501][501];
int dist[505];
bool visit[501][501];
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
		for (int i = 0; i < n; i++) {
			if (a[here][i] == -1) continue;
			if (dist[i] > dist[here] + a[here][i]) {
				dist[i] = dist[here] + a[here][i];
				pq.push({ dist[i],i });
			}
		}
	}

}
void bfs(int en,int st,int n) {
	queue<int> q;
	q.push(en);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (dist[here] == dist[i] + a[i][here] && a[i][here] != -1) {
				a[i][here] = -1;
				q.push(i);
			}
		}
	}
}
int main(void) {
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		scanf("%d%d", &st, &en);
		memset(a, -1, sizeof(a));
		memset(dist, 0, sizeof(dist));
		memset(visit, false, sizeof(visit));
		for (int i = 1; i <= m; i++) {
			int left, right, cost;
			scanf("%d%d%d", &left, &right, &cost);
			a[left][right] = cost;
		}
		dijk(st);
		bfs(en,st,n);
		dijk(st);
		dist[en] == 1e9 ? printf("-1\n") : printf("%d\n", dist[en]);
	}
	return 0;
}