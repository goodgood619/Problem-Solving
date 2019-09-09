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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
using namespace std;
int n, m;
vector<vector<int>> big, small;
bool visited[105];
int dfs(int here) {
	visited[here] = true;
	int ret = 0;
	for (int i = 0; i < big[here].size(); i++) {
		int next = big[here][i];
		if (!visited[next]) {
			ret += dfs(next);
		}
	}
	ret++;
	return ret;
}
int dfs2(int here) {
	visited[here] = true;
	int ret = 0;
	for (int i = 0; i < small[here].size(); i++) {
		int next = small[here][i];
		if (!visited[next]) {
			ret += dfs2(next);
		}
	}
	ret++;
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	big.resize(n + 1), small.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		big[first].push_back(second);
		small[second].push_back(first);
	}
	vector<int> ans1, ans2;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		int cnt = dfs(i);
		cnt--;
		ans1.push_back(cnt);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		int cnt = dfs2(i);
		cnt--;
		ans2.push_back(cnt);
	}
	int ans = 0;
	for (int i = 0; i < ans1.size(); i++) {
		if (ans1[i] >=(n + 1) / 2) ans++;
	}
	for (int i = 0; i < ans2.size(); i++) {
		if (ans2[i] >=(n + 1) / 2) ans++;
	}
	printf("%d\n", ans);
	return 0;
}