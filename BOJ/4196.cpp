#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
using namespace std;
vector<vector<int>> a;
vector<vector<int>> scc;
int n, m, cnt;
int sccnt = 1;
int scnum[100005];
bool finished[100005];
int dfsorder[100005];
stack<int> st;
int dfs(int here) {
	dfsorder[here] = ++cnt;
	//visited[here] = true;
	st.push(here);
	int result = dfsorder[here];
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!dfsorder[next]) result = min(result, dfs(next));
		else if (!finished[next]) result = min(result, dfsorder[next]);
	}
	if (result == dfsorder[here]) {
		// 나올때까지 뽑는다.
		vector<int> temp;
		while (1) {
			int top = st.top();
			temp.push_back(top);
			st.pop();
			finished[top] = true; // 여기서 이제 할일이 다끝났음 ㅇㅇ
			scnum[top] = sccnt;
			if (top == here) break; // top==dfsorder[here]는 절대 아닌게 어차피, 순서인거고, 우리는 그냥 그 정점까지 찾는게 목표이다. 그래서 top==here인것
		}
		scc.push_back(temp);
		sccnt++;
	}
	return result;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		sccnt = 1;
		cnt = 0;
		a.clear();
		scc.clear();
		memset(finished, false, sizeof(finished));
		memset(dfsorder, 0, sizeof(dfsorder));
		memset(scnum, 0, sizeof(scnum));
		a.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back(second);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfsorder[i]) dfs(i);
		}
		int outdegree[100005] = { 0, };
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int next = a[i][j];
				if (scnum[i] != scnum[next]) outdegree[scnum[next]]++;
			}
		}
		int ans = 0;
		for (int i = 1;i<sccnt; i++) {
			if (outdegree[i] == 0) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}