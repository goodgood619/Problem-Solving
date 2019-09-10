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
#define mod 1000000009
#define lim 1000000000
typedef pair < int,int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { -1,1,0,0 };
int goy[4] = { 0,0,-1,1 };
int n, m;
vector<vector<int>> a;
vector<int> temp;
bool visited[1005][15];
void dfs(int here,int eat) {
	if (here == n+1) {
		for (int i = 0; i < temp.size(); i++) {
			printf("%d\n", temp[i]);
		}
		exit(0);
	}
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (next == eat) continue;
		if (!visited[here][next]) {
			visited[here][next] = true;
			temp.push_back(next);
			dfs(here + 1, next);
			temp.pop_back();
		}
	}
}
int main(void) {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 1; j <= cnt; j++) {
			int num;
			scanf("%d", &num);
			a[i].push_back(num);
		}
	}
	dfs(1, 0);
	printf("-1\n");
	return 0;
}