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
int t,ok;
int Case = 1;
bool visited[105];
vector<vector<int>> a;
void dfs(int here) {
	if (here == 99) {
		ok = 1;
	}
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main() {
	int t = 10;
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		a.clear();
		a.resize(105);
		ok = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= m; i++) {
			int left, right;
			scanf("%d%d", &left, &right);
			a[left].push_back(right);
		}
		dfs(0);
		printf("#%d %d\n", n, ok);
	}
	return 0;
}