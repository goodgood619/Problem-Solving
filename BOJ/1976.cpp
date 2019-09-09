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
int parent[201];
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
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			scanf("%d", &num);
			if (num == 1) uni(i, j);
		}
	}
	vector<int> v;
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	int no = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int here = v[i], next = v[i + 1];
		int heretop = find(here),nexttop=find(next);
		if (heretop == nexttop) continue;
		else {
			no = 1;
			break;
		}
	}
	no ? printf("NO\n") : printf("YES\n");
	return 0;
}