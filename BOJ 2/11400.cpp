#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
int n, m,t;
vector<vector<int>> a;
vector<pair<int, int>> cutline;
int dis[100001];
int dfs(int here,int parent) {
	dis[here] = ++t;
	int ret = dis[here];
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (next == parent) continue;
		if (!dis[next]) {
			int r = dfs(next, here);
			if (r > dis[here]) {
				cutline.push_back({ min(next,here),max(next,here) });
			}
			ret = min(ret, r);
		}
		else ret = min(ret, dis[next]);
	}

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
		if (!dis[i]) dfs(i, 0);
	}
	printf("%d\n", cutline.size());
	sort(cutline.begin(), cutline.end());
	for (int i = 0; i < cutline.size(); i++) printf("%d %d\n", cutline[i].first, cutline[i].second);
	return 0;
}