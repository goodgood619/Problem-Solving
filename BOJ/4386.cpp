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
typedef pair<double, pair<int, int>> PPP;
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
	scanf("%d", &n);
	priority_queue<PPP, vector<PPP>, greater<PPP>> pq;
	for (int i = 1; i <= n; i++) parent[i] = i;
	vector<pair<double, double>> v;
	for (int i = 1; i <= n; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		v.push_back({ x,y });
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			double a = v[i].first - v[j].first, b = v[i].second - v[j].second;
			double dist = sqrt(a*a + b * b);
			pq.push({ dist,{i + 1,j + 1} });
		}
	}
	double ans = 0;
	while (!pq.empty()) {
		double cost = pq.top().first;
		int here = pq.top().second.first;
		int next = pq.top().second.second;
		pq.pop();
		int heretop = find(here), nexttop = find(next);
		if (heretop != nexttop) {
			uni(here, next);
			ans += cost;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}