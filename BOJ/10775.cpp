#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <map>
using namespace std;
int n, m;
int parent[100005];
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
int uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 0;
	parent[u] = v;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { parent[i] = i;}
	scanf("%d", &m);
	int ok = 0;
	for (int i = 1; i <= m; i++) {
		int what;
		scanf("%d", &what);
		int whattop = find(what);
		if (whattop == 0) break;
		else {
			uni(whattop, whattop - 1);
			ok++;
		}
	}
	printf("%d\n", ok);
	return 0;
}