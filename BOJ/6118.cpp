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
int n, m,via1,via2;
vector<vector<P>> a;
void dijk(int st) {
	int dist[20005] = { 0, };
	for (int i = 1; i <= n; i++)  dist[i] = 1e8 * 5;
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
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
			}
		}
	}
	int Max = 0,idx=1e9,cnt=0;
	for (int i = 1; i <= n; i++) {
		Max = max(Max, dist[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (Max == dist[i]) {
			idx = min(idx, i);
			cnt++;
		}
	}
	printf("%d %d %d\n", idx, dist[idx], cnt);
}
int main(void) {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		a[left].push_back({ right,1 });
		a[right].push_back({ left,1 });
	}
	dijk(1);
	return 0;
}