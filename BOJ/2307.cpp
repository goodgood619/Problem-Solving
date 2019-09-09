
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
typedef pair<int, pair<ll,char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n,m;
vector<vector<P>> a;
int dist[1005];
int path[1005];
int dijk(int here) {
	for (int i = 1; i <= n; i++)dist[i] = 1e9;
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,here });
	dist[here] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		if (here == n) return cost;
		pq.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				path[next] = here;
				pq.push({ dist[next],next });
			}
		}
	}
	return -1;
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
	int curcost=dijk(1);
	// 역추적을 해서, 나온 거리들의 list들이 있으면, 걔네를 한개씩 없애보면서 진행을 한다
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
		for (int j = 0; j < a[here].size(); j++) {
			if (next == a[here][j].first) {
				int p = a[here][j].second;
				a[here][j].second = 1e9;
				int d=dijk(1);
				if (d == -1) {
					printf("-1\n");
					return 0;
				}
				else {
					Max=max(d - curcost, Max);
				}
				a[here][j].second = p;
				break;
			}
		}
	}
	printf("%d\n", Max);
	return 0;
}
