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
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
vector<vector<int>> a;
int n, m, st;
bool visited[1005];
void dfs(int here) {
	visited[here] = true;
	printf("%d ", here);
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) dfs(next);
	}
}
void bfs(int here) {
	queue<int> q;
	q.push(here);
	visited[here] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		printf("%d ", here);
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}
int main(void) {
	scanf("%d%d%d", &n, &m, &st);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(st);
	printf("\n");
	memset(visited, false, sizeof(visited));
	bfs(st);
	printf("\n");
	return 0;
}