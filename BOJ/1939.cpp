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
#define mod 1000000007
typedef pair<int,ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m,st,en;
vector<vector<P>> a;
bool bfs(int st, int en, ll cost) { // cost 비용으로 도달할수 있는지없는지
	queue<P> q;
	bool visited[100006] = { false, };
	q.push({ st,cost });
	while (!q.empty()) {
		int here = q.front().first;
		ll cost = q.front().second;
		q.pop();
		if (here == en) return true;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			ll nextcost = a[here][i].second;
			if (cost > nextcost) continue;
			else if (!visited[next]) {
				visited[next] = true;
				q.push({ next,cost });
			}
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		ll cost;
		scanf("%d%d%lld", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	scanf("%d%d", &st, &en);
	ll left = 1;
	ll right = 1e10;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (!bfs(st, en, mid)) right = mid - 1; //무거워서 불가능, 무게줄여야함
		else left = mid + 1; // 가벼워서 가능,무게늘려도됨
	}
	printf("%lld\n", left-1);
	return 0;
}