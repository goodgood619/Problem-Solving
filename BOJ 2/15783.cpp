
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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,m,num;
vector<vector<int>> a;
int indegree[100001];
int scc[100001];
int dis[100001];
stack<int> st;
int dfs(int here) {
	st.push(here);
	dis[here] = ++t;
	int ret = dis[here];
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!dis[next]) ret = min(ret, dfs(next));
		if (!scc[next]) ret = min(ret, dis[next]);
	}
	if (ret == dis[here]) {
		++num;
		while (1) {
			int high = st.top();
			st.pop();
			scc[high] = num;
			if (high == here) break;
		}
	}
	return ret;
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
	}
	for (int i = 0; i <n; i++) {
		if (!dis[i]) dfs(i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			int next = a[i][j];
			if (scc[i] != scc[next]) indegree[scc[next]]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= num; i++) {
		if (!indegree[i]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
