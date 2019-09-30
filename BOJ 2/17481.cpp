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
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int dfs(int here,bool visited[],vector<vector<int>> &graph,int path[]) {
	if (visited[here]) return 0;
	visited[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		int next = graph[here][i];
		if (path[next] == -1 || dfs(path[next],visited,graph,path) == 1) {
			path[next] = here;
			return 1;
		}
	}
	return 0;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	map<string, int> girlgroup;
	vector<vector<int>> graph;
	bool visited[1001] = { false, };
	int path[1001] = { 0, };
	int dir = 1;
	for (int i = 1; i <= 1000; i++) visited[i] = false;
	memset(path, -1, sizeof(path));
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		girlgroup[s] = dir++;
	}
	graph.assign(n + 1, vector<int>(0, 0));
	for (int i = 1; i <= n; i++) {
		int work;
		scanf("%d", &work);
		for (int j = 1; j <= work; j++) {
			string s;
			cin >> s;
			int num = girlgroup[s];
			graph[i].push_back(num);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i,visited,graph,path)) ans++;
	}
	ans == n ? printf("YES\n") : printf("NO\n%d\n", ans);
	return 0;
}