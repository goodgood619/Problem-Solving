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
typedef pair<int, int> P;
typedef pair<pair<ll, ll>, ll> PP;
typedef pair<ll, pair<ll, ll >> PPP;
typedef pair<pair<ll, ll>, pair<ll, ll>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, q;
vector<PP> v;
int parent[250005];
int ans[250005];
priority_queue<PPP, vector<PPP>, greater<PPP>> pq;
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
bool compare(const PP &a, const PP &b) { //x좌표우선정렬
	if (a.first.first != b.first.first) return a.first.first < b.first.first;
	if (a.first.second != b.first.second) return a.first.second < b.first.second;
}
bool compare2(const PP &a, const PP &b) { // y좌표우선정렬
	if (a.first.second != b.first.second) return a.first.second < b.first.second;
	if (a.first.first != b.first.first) return a.first.first < b.first.first;
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		v.push_back({ {x,y },i });
	}
	sort(v.begin(), v.end());
	vector<PP> temp = v;
	vector<PP> temp2 = v;
	sort(temp.begin(),temp.end(), compare);
	sort(temp2.begin(), temp2.end(), compare2);
	//인접한 x좌표, y좌표끼리 연결 ㄱㄱ
	for (int i = 0; i < temp.size()-1; i++) { //x좌표 연결(부스터길을 연결한것과 같음
		ll diff = abs(temp[i].first.first - temp[i + 1].first.first);
		pq.push({ diff,{temp[i].second,temp[i + 1].second}});
	}
	for (int i = 0; i < temp2.size() - 1; i++) { //인접한 y좌표연결(부스터길을 연결한것과 같음)
		ll diff = abs(temp2[i].first.second - temp2[i + 1].first.second);
		pq.push({ diff,{temp2[i].second,temp2[i + 1].second} });
	}
	vector<PPPP> query;
	for (int i = 1; i <= q; i++) {
		ll a, b, x;
		scanf("%lld%lld%lld", &a, &b, &x);
		query.push_back({{x,i }, {a, b}});
	}
	sort(query.begin(), query.end());
	for (int i = 0; i < query.size(); i++) {
		PPPP here = query[i];
		ll hp=query[i].first.first,idx=query[i].first.second, left = query[i].second.first,right=query[i].second.second;
		while (!pq.empty()) {
			ll herehp = pq.top().first;
			ll l = pq.top().second.first;
			ll r = pq.top().second.second;
			if (hp < herehp) break;
			uni(l, r);
			pq.pop();
		}
		if (find(left) == find(right)) {
			ans[idx] = 1;
		}
	}

	for (int i = 1; i <= q; i++) {
		if (ans[i] == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}