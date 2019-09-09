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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int parent[100005];
ll dist[100005];
int Size[100005]; //???? 이거를 구지 왜할까라는 생각이드네
int find(int u) { //여기서 딱히 갱신을 안시킴
	if (u == parent[u]) return u;
	int pu = find(parent[u]);
	dist[u] += dist[parent[u]];
	return parent[u] = pu;
}
void uni(int u, int v, ll cost) {
	int A = find(u);
	int B = find(v);
	if (A==B) return;
	ll leftcost = dist[u];
	ll rightcost = dist[v];
	dist[A] = cost - leftcost + rightcost;
	parent[A] = B;
}
int main() {
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		else {
			memset(dist, 0, sizeof(dist));
			for (int i = 1; i <= n; i++) {
				parent[i] = i;
			}
			for (int i = 1; i <= m; i++) {
				char what;
				scanf(" %c", &what);
				if (what == '!'){
					int a, b;
					ll cost;
					scanf("%d%d%lld", &a, &b, &cost);
					uni(a, b, cost);
				}
				else {
					int a, b;
					scanf("%d%d", &a, &b);
					int atop = find(a);
					int btop = find(b);
					if (atop!=btop) {
						printf("UNKNOWN\n");
					}
					else {
						printf("%lld\n", dist[a] -dist[b]);
					}
				}
			}
		}
	}
	return 0;
}