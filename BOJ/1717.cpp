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
int parent[1000001];
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void uni(int u,int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	parent[u] = v;
}
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0) {
			int btop = find(b);
			int ctop = find(c);
			if (btop != ctop) uni(b, c);
		}
		else {
			int btop = find(b);
			int ctop = find(c);
			btop == ctop ? printf("YES\n") : printf("NO\n");
		}
	}
	return 0;
}