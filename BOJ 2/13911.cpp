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
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m,mac,star,macx,starx;
vector<vector<P>> a;
int macdist[10001],stardist[10001];
priority_queue<P, vector<P>, greater<P>> pq;
void dijk() {
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (macdist[here] > cost) continue;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (macdist[next] > macdist[here] + nextcost) {
				macdist[next] = macdist[here] + nextcost;
				pq.push({ macdist[next],next });
			}
		}
	}
}
void dijk2() {
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (stardist[here] > cost) continue;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (stardist[next] > stardist[here] + nextcost) {
				stardist[next] = stardist[here] + nextcost;
				pq.push({ stardist[next],next });
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	for (int i = 1; i <= n; i++) {
		macdist[i] = 2e9, stardist[i] = 2e9;
	}
	scanf("%d%d", &mac, &macx);
	for (int i = 1; i <= mac; i++) {
		int pos;
		scanf(" %d", &pos);
		macdist[pos] = 0;
		pq.push({ 0,pos });
	}
	dijk();
	while (!pq.empty()) pq.pop();
	scanf("%d%d", &star, &starx);
	for (int i = 1; i <= star; i++) {
		int pos;
		scanf(" %d", &pos);
		stardist[pos] = 0;
		pq.push({ 0,pos });
	}
	dijk2();
	int Min = 2e9;
	for (int i = 1; i <= n; i++) {
		if (macdist[i] <= macx && stardist[i] <= starx && macdist[i]>0 && stardist[i]>0) {
			Min = min(Min, macdist[i] + stardist[i]);
		}
	}
	Min == 2e9 ? printf("-1") : printf("%d\n", Min);
	return 0;
}