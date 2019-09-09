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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, k;
vector<P> v;
int dist(int x1, int y1, int x2, int y2) {
	int d = ceil(sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
	if (d % 10 == 0) return d / 10;
	else return d / 10 + 1;
}
int bfs(int gas) {
	bool visited[1005] = { false, };
	queue<P> q;
	q.push({ 0,0 });
	visited[0] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		if (here == v.size() - 1) {
			if (cnt - 1 <= k) return 1;
			else return 0;
		}
		q.pop();

		for (int i = 0; i < v.size(); i++) {
			if (visited[i]) continue;
			else if (!visited[i] && dist(v[here].first, v[here].second, v[i].first, v[i].second) <= gas) {
				visited[i] = true;
				q.push({ i,cnt + 1 });
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &k);
	v.push_back({ 0,0 });
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back({ x,y });
	}
	v.push_back({ 10000,10000 });
	int left = 1, right = dist(0, 0, 10000, 10000);
	int ans = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (bfs(mid)) {
			right = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%d\n",left);
	return 0;
}