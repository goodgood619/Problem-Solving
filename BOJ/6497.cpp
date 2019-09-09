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
int n, m,total;
bool visited[200005];
vector<vector<pair<int, int>>> a;
void prim(int st) {
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (visited[here]) continue;
		visited[here] = true;
		total += cost;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (!visited[next]) pq.push({ nextcost,next });
		}
	}
}
int main() {
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		a.clear();
		total = 0;
		a.resize(n + 1);
		int ans = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= m; i++) {
			int here, second, cost;
			scanf("%d%d%d", &here, &second, &cost);
			a[here].push_back({ second,cost });
			a[second].push_back({ here,cost });
			ans += cost;
		}
		prim(0);
		printf("%d\n", ans-total);
	}
	return 0;
}