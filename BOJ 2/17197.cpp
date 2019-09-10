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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1, n, m, minx=1e9, miny=1e9, maxx, maxy;
vector<vector<int>> a;
vector<pair<int, int>> v;
bool visited[100001];
void dfs(int here,int x,int y) {
	minx = min(minx, x);
	miny = min(miny, y);
	maxx = max(maxx, x);
	maxy = max(maxy, y);
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next,v[next-1].first,v[next-1].second);
		}
	}
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back({ x,y });
	}

	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	int ans=1e9;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			minx = 1e9, miny = 1e9, maxx = 0, maxy = 0;
			dfs(i, v[i - 1].first, v[i - 1].second);
			ans = min(ans, 2 * (abs(minx - maxx) + abs(miny - maxy)));
		}
	}
	printf("%d\n",ans);
	return 0;
}