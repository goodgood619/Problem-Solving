#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m,t;
vector<vector<int>> a;
int dis[10001];
bool cutvertex[10001];
vector<int> v;
int dfs(int here,bool ok) {
	dis[here] = ++t;
	int child = 0;
	int ret = dis[here];
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!dis[next]) {
			child++;
			int r = dfs(next, false);
			if (!ok && r >= dis[here]) {
				cutvertex[here] = true;
			}
			ret = min(ret, r);
		}
		else ret = min(ret, dis[next]);
	}
	if (ok && child >= 2) cutvertex[here] = true;
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}

	for (int i = 1; i <= n; i++) {
		if (!dis[i]) dfs(i, true);
	}
	for (int i = 1; i <= n; i++) {
		if (cutvertex[i]) v.push_back(i);
	}
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
	return 0;
}