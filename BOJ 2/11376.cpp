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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
bool visited[1005];
int n, m;
int path[1005];
vector<vector<int>> a;
int dfs(int here) {
	if (visited[here]) return 0;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (path[next] == -1 || dfs(path[next]) == 1) {
			path[next] = here;
			return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int work;
		scanf("%d", &work);
		for (int j = 1; j <= work; j++) {
			int num;
			scanf("%d", &num);
			a[i].push_back(num);
		}
	}
	memset(path, -1, sizeof(path));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) ans++;
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}