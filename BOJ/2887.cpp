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
typedef pair<pair<int, int>, pair<int,int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n;
int parent[100005];
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
bool compare1(const PP &a, const PP &b) {
	if (a.first.second != b.first.second) return a.first.second < b.first.second;
}
bool compare2(const PP &a, const PP &b) {
	if (a.second.first != b.second.first) return a.second.first < b.second.first;
}
bool compare3(const PP &a, const PP &b) {
	if (a.second.second != b.second.second) return a.second.second < b.second.second;
}
int main() {
	scanf("%d", &n);
	vector<PP> v;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v.push_back({{ i,x }, { y,z }});
	}
	priority_queue<PPP, vector<PPP>, greater<PPP>> pq;
	vector<PP> temp = v;
	sort(temp.begin(),temp.end(),compare1);
	for (int i = 0; i < temp.size()-1; i++) {
		PP a = temp[i];
		PP b = temp[i + 1];
		int dist = min(abs(a.second.second - b.second.second), min(abs(a.first.second - b.first.second), abs(a.second.first - b.second.first)));
		pq.push({ dist,{a.first.first,b.first.first}});
	}
	temp = v;
	sort(temp.begin(), temp.end(), compare2);
	for (int i = 0; i < temp.size() - 1; i++) {
		PP a = temp[i];
		PP b = temp[i + 1];
		int dist = min(abs(a.second.second - b.second.second), min(abs(a.first.second - b.first.second), abs(a.second.first - b.second.first)));
		pq.push({ dist,{a.first.first,b.first.first} });
	}
	temp = v;
	sort(temp.begin(), temp.end(), compare3);
	for (int i = 0; i < temp.size() - 1; i++) {
		PP a = temp[i];
		PP b = temp[i + 1];
		int dist = min(abs(a.second.second - b.second.second), min(abs(a.first.second - b.first.second), abs(a.second.first - b.second.first)));
		pq.push({ dist,{a.first.first,b.first.first} });
	}
	ll ans = 0;
	int cnt = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second.first;
		int next = pq.top().second.second;
		pq.pop();
		if (find(here) != find(next)) {
			uni(here, next);
			ans += (ll)cost;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	printf("%lld\n", ans);
	return 0;
}