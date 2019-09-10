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
int parent[10001];
int cost[10001];
int Size[10001];
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void uni(int u,int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (cost[u] > cost[v]) {
		parent[u] = v;
		Size[v] += Size[u];
		Size[u] = 0;
	}
	else {
		parent[v] = u;
		Size[u] += Size[v];
		Size[v] = 0;
	}
}
int n, m,c;
int main() {
	scanf("%d%d%d", &n, &m,&c);
	for (int i = 1; i <= n; i++) parent[i] = i, Size[i] = 1;
	for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);
	for (int i = 0; i < m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		int heretop = find(first),nexttop=find(second);
		if (heretop == nexttop) continue;
		else uni(first, second);
	}
	int no = 0;
	int rest = 0;
	int p = c;
	for (int i = 1; i <= n; i++) {
		if (Size[i]) {
			c -= cost[i];
			rest += cost[i];
			if (c < 0) {
				no = 1;
				break;
			}
		}
	}
	no ? printf("Oh no\n") : printf("%d\n",rest);
	return 0;
}