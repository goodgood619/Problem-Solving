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
typedef pair <int, int > P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,-1,1,1,-1 };
int t, Case = 1,n,m;
vector<vector<int>> a;
bool visited[15];
int dfs(int here, int cnt) {
	int ret = cnt;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			ret=max(ret,dfs(next, cnt + 1));
		}
	}
	visited[here] = false;
	return ret;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		a.clear();
		a.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back(second);
			a[second].push_back(first);
		}
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, dfs(i, 1));
		}
		printf("#%d %d\n", Case++, ans);
	}
	return 0;
}