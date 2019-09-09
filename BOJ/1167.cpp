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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n,del,cnt,st,Max;
vector<vector<pair<int,int>>> a;
bool visited[100001];
void dfs(int here,int cost) {
	if (Max < cost) {
		Max = cost;
		st = here;
	}
	visited[here] = true;
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
	for (int i = 1; i <= n; i++) {
		int here;
		scanf("%d", &here);
		while (1) {
			int next;
			scanf("%d", &next);
			if (next == -1) break;
			else {
				int cost;
				scanf("%d", &cost);
				a[here].push_back({ next,cost });
			}
		}
	}
	dfs(1, 0);
	Max = 0;
	dfs(st, 0);
	printf("%d\n", Max);
	return 0;
}