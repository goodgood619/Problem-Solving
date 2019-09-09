#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<vector<P>> a;
int t, n, m;
bool visited[1005];
int dfs(int here, int precost) {
	visited[here] = true;
	int sum = 0;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i].first;
		int nextcost = a[here][i].second;
		if (!visited[next]) {
			sum += dfs(next, nextcost);
		}
	}
	if (sum == 0) return precost;
	if (sum < precost) return sum;
	else return precost;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		a.clear();
		memset(visited, false, sizeof(visited));
		scanf("%d%d", &n, &m);
		a.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int first, second, cost;
			scanf("%d%d%d", &first, &second, &cost);
			a[first].push_back({ second,cost });
			a[second].push_back({ first,cost });
		}
		printf("%d\n", m?dfs(1, 1e9):0);
	}
	return 0;
}