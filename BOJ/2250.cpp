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
int n,ptr,Max=-1;
vector<vector<int>> a,depth;
bool visited[10001];
int indegree[10001];
void dfs(int here,int dep) {
	if (a[here][0] != -1) dfs(a[here][0],dep+1);
	depth[dep].push_back(++ptr);
	if (a[here][1] != -1) dfs(a[here][1],dep+1);
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	depth.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int here, left, right;
		scanf("%d%d%d", &here, &left, &right);
		a[here].push_back(left);
		a[here].push_back(right);
		indegree[left]++, indegree[right]++;
	}
	int st = 0;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			st = i;
			break;
		}
	}
	dfs(st,1);
	int t = 0;
	for (int i = 1; i <= n; i++) {
		if (depth[i].size() >= 1) {
			int dist = abs(depth[i][0] - depth[i][depth[i].size() - 1]);
			if (Max < dist) {
				Max = dist;
				t = i;
			}
		}
	}
	printf("%d %d\n", t, Max + 1);
	return 0;
}