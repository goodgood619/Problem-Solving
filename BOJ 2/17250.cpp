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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int Size[100001];
int parent[100001];
int find(int u) {
	if (parent[u] == u) return u;
	else return parent[u] = find(parent[u]);
}
int uni(int u,int v) {
	u = find(u);
	v = find(v);
	if (u == v) return Size[u];
	if (Size[v] > Size[u]) {
		Size[v] += Size[u];
		Size[u] = 0;
		parent[u] = v;
		return Size[v];
	}
	else {
		Size[u] += Size[v];
		Size[v] = 0;
		parent[v] = u;
		return Size[u];
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &Size[i]);
	}
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		int firsttop = find(first), secondtop = find(second);
		if (firsttop != secondtop) {
			printf("%d\n",uni(first, second));
		}
		else printf("%d\n", Size[firsttop]);
	}
	return 0;
}