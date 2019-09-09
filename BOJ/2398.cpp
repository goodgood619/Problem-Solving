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
int n, m;
vector<vector<P>> a;
vector<P> route;
int dist[1005][1005];
int path[1005][1005];
vector<int> v;
void dijk() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dist[i][j] = 1e9;
		}
	}
	priority_queue<PP, vector<PP>, greater<PP>> pq;
	pq.push({ 0,{v[0],v[0]} }), pq.push({ 0,{v[1],v[1]} }), pq.push({ 0,{v[2],v[2]}});
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second.first;
		int start = pq.top().second.second;
		pq.pop();
		if (cost > dist[here][start]) continue;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (dist[next][start] > dist[here][start] + nextcost) {
				dist[next][start] = dist[here][start] + nextcost;
				pq.push({ dist[next][start],{next,start}});
				path[next][start] = here;
			}
		}
	}
}
void makepath(int en,int here) {
	while (path[en][here]!=0) {
		route.push_back({ en,path[en][here] });
		en = path[en][here];
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int left, right, cost;
		scanf("%d%d%d", &left, &right, &cost);
		a[left].push_back({ right,cost });
		a[right].push_back({ left,cost });
	}
	for (int i = 0; i < 3; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	dijk();
	int ans = 1e9,st=-1;
	for (int i = 1; i <= n; i++) {
		if (ans > dist[i][v[0]] + dist[i][v[1]] + dist[i][v[2]]) {
			ans = dist[i][v[0]] + dist[i][v[1]] + dist[i][v[2]];
			st = i;
		}
	}

	makepath(st, v[0]);
	makepath(st, v[1]);
	makepath(st, v[2]);

	printf("%d %d\n", ans, route.size());
	for (int i = 0; i < route.size(); i++) {
		printf("%d %d\n", route[i].first, route[i].second);
	}
	return 0;
}