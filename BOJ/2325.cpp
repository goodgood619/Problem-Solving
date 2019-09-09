
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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int dist[1005];
int path[1005];
vector<vector<P>> a;
int dijk(int here) {
	priority_queue<P, vector<P>, greater<P>> pq;
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	pq.push({ 0,here });
	dist[here] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (here == n) return cost;
		if (cost > dist[here]) continue;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (nextcost == -1) continue;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
				path[next] = here;
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
	dijk(1);
	int p = n;
	vector<int> v;
	while (p != 1) {
		v.push_back(p);
		p = path[p];
	}
	v.push_back(1);
	reverse(v.begin(), v.end());
	int Max = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int here = v[i];
		int next = v[i + 1];
		int idx1 = 0,idx2=0,p1=0,p2=0;
		for (int j = 0; j < a[here].size(); j++) {
			int what = a[here][j].first;
			if (what == next) {
				p1 = a[here][j].second;
				a[here][j].second = -1;
				idx1 = j;
				break;
			}
		}
		for (int k = 0; k < a[next].size(); k++) {
			int what = a[next][k].first;
			if (what == here) {
				p2 = a[next][k].second;
				a[next][k].second = -1;
				Max = max(Max, dijk(1));
				idx2 = k;
				break;
			}
		}
		a[here][idx1].second = p1;
		a[next][idx2].second = p2;
	}
	printf("%d\n", Max);
	return 0;
}