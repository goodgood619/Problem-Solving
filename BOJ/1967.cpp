#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int n,cnt,Max,start;
vector<vector<pair<int,int>>> a;
bool visited[10005];
void dfs(int here,int cost) {
	visited[here] = true;
	if (Max<cost) {
		Max = cost;
		start = here;
	}
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i].first;
		int nextcost = a[here][i].second;
		if (!visited[next]) {
			dfs(next, cost + nextcost);
		}
	}
	visited[here] = false;
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <n; i++) {
		int here, next, cost;
		scanf("%d%d%d", &here, &next, &cost);
		a[here].push_back({ next,cost });
		a[next].push_back({ here,cost });
	}
	dfs(1, 0);
	Max = 0;
	dfs(start, 0);
	printf("%d\n", Max);
	return 0;
}