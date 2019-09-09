#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> a;
vector<vector<int>> v;
int n, m, total,t;
int dis[10001];
int scc[10001];
stack<int> st;
int dfs(int here) {
	dis[here] = ++t;
	int ret = dis[here];
	st.push(here);
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!dis[next]) ret = min(ret, dfs(next));
		if (!scc[next]) ret = min(ret, dis[next]);
	}

	if (ret == dis[here]) {
		vector<int> temp;
		while (1) {
			int a = st.top();
			st.pop();
			scc[a] = 1;
			temp.push_back(a);
			if (a == here) break;
		}
		sort(temp.begin(), temp.end());
		v.push_back(temp);
		total++;
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
	}
	for (int i = 1; i <= n; i++) {
		if (!dis[i]) dfs(i);
	}
	printf("%d\n", total);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			printf("%d ", v[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}