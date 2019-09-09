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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int parent[100001];
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void uni(int u,int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	parent[u] = v;
}
int n, m,c;
int main() {
	scanf("%d%d", &n, &m);
	priority_queue<PPP, vector<PPP>, greater<PPP>> pq;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int first, second,cost;
		scanf("%d%d%d", &first, &second,&cost);
		pq.push({ cost,{first,second} });
	}
	int ans = 0,Max=0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second.first;
		int next = pq.top().second.second;
		pq.pop();
		int heretop = find(here), nexttop = find(next);
		if (heretop != nexttop) {
			uni(here, next);
			Max = max(Max, cost);
			ans += cost;
		}
	}
	printf("%d\n", ans-Max);
	return 0;
}