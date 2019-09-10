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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m,c,h,k;
vector<vector<int>> a;
int parent[100005];
int Size[100005];
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void uni(int u,int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (Size[u] < Size[v]) {
		Size[v] += Size[u];
		Size[u] = 0;
		parent[u] = v;
	}
	else {
		Size[u] += Size[v];
		Size[v] = 0;
		parent[v] = u;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) Size[i] = 1;
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		int firsttop = find(first);
		int secondtop = find(second);
		if (firsttop != secondtop) uni(first, second);
	}
	scanf("%d%d%d", &c, &h, &k);
	priority_queue<P, vector<P>> pq;
	for (int i = 1; i <= n; i++) {
		if (Size[i] != 0) pq.push({ Size[i],i });
	}
	int cnt = 0;
	while (!pq.empty()) {
		if (cnt == k) break;
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		int heretop = find(here);
		int htop = find(h);
		if (heretop != htop) {
			uni(c, here);
			cnt++;
		}
	}
	printf("%d\n", Size[find(c)]);
	return 0;

}