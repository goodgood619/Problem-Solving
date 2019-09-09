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
int n, m, x;
vector<vector<P>> a;
int dist[1005];
int dist2[1005];
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
void djik2(int st) {
	int temp[1005] = { 0, };
	for (int i = 1; i <= n; i++) temp[i] = 1e9;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,st });
	temp[st] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (cost > temp[here]) continue;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (temp[next] > temp[here] + nextcost) {
				temp[next] = temp[here] + nextcost;
				pq.push({ temp[next],next });
			}
		}
	}
	dist2[st] = temp[x];
}
int main(void) {
	scanf("%d%d%d", &n, &m, &x);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int left, right, cost;
		scanf("%d%d%d", &left, &right, &cost);
		a[left].push_back({ right,cost });
	}
	for (int i = 1; i <= n; i++) {
		djik2(i);
	}
	dijk(x);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dist[i] + dist2[i]);
	}
	printf("%d\n", ans);
	return 0;
}