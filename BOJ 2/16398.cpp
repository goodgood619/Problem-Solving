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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int n;
vector<int> v;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int parent[1005];
priority_queue<PP, vector<PP>, greater<PP>> pq;
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			scanf("%d", &num);
			pq.push({ num,{i,j}});
		}
	}
	for (int i = 1; i <= 1000; i++)parent[i] = i;
	ll ans = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second.first;
		int next = pq.top().second.second;
		pq.pop();
		int heretop = find(here);
		int nexttop = find(next);
		if (heretop != nexttop) {
			uni(here, next);
			ans += (ll)cost;
		}
	}
	printf("%lld\n", ans);
	return 0;
}