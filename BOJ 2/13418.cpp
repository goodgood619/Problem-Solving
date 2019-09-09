#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m,Min,Max;
priority_queue<PP, vector<PP>, greater<PP>> pq;
priority_queue<PP, vector<PP>> pq2;
int parent[1005];
vector<PP> v;
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <=m+1; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		if (cost == 0) cost = 1;
		else cost = 0;
		v.push_back({ cost,{first,second} });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		pq.push({ v[i].first,{v[i].second.first,v[i].second.second}});
		pq2.push({ v[i].first,{ v[i].second.first,v[i].second.second}});
	}
	for (int i = 0; i <= n; i++) parent[i] = i;
	while (!pq.empty()){
		int cost = pq.top().first;
		int here1 = pq.top().second.first;
		int here2 = pq.top().second.second;
		pq.pop();
		int here1top = find(here1);
		int here2top = find(here2);
		if (here1top != here2top) {
			uni(here1, here2);
			Min += cost;
		}
	}
	for (int i = 0; i <= n; i++) parent[i] = i;
	while (!pq2.empty()) {
		int cost = pq2.top().first;
		int here1 = pq2.top().second.first;
		int here2 = pq2.top().second.second;
		pq2.pop();
		int here1top = find(here1);
		int here2top = find(here2);
		if (here1top != here2top) {
			uni(here1, here2);
			Max += cost;
		}
	}
	printf("%d\n", Max*Max - Min * Min);
	return 0;
}