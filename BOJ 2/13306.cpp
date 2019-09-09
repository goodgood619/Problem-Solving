#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int n,k;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
PP query[400005];
vector<vector<int>> a;
bool visited[200005];
int parent[200005];
string ans[200005];
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
	return;
}
int main(){
	scanf("%d%d", &n, &k);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 2; i <= n; i++){
		int what;
		scanf("%d", &what);
		a[i].push_back(what);
	}
	for (int i = 1; i <= n - 1 + k; i++) {
		int what;
		scanf("%d", &what);
		if (what == 0){
			int who;
			scanf("%d", &who);
			query[i].first = what;
			query[i].second.first = who;
			query[i].second.second = -1;
		}
		else{
			int a, b;
			scanf("%d%d", &a, &b);
			query[i].first = what;
			query[i].second.first = a;
			query[i].second.second = b;
		}
	}
	int p = k;
	int temp = p;
	p--;
	for (int i = n - 1 + k; i >= 1; i--) {
		int choice = query[i].first;
		if (choice == 0) {
			int here = query[i].second.first;
			for (int j = 0; j < a[here].size(); j++) {
				int next = a[here][j];
				int heretop = find(here);
				int nexttop = find(next);
				if (find(heretop) != nexttop) {
					merge(here, next);
				}
			}
		}
		else {
			int from = query[i].second.first;
			int to = query[i].second.second;
			if (find(from) == find(to)) {
				ans[p].push_back('Y');
				p--;
			}
			else {
				ans[p].push_back('N');
				p--;
			}
		}
	}
	for (int i = 0; i < temp; i++) {
		if (ans[i][0] == 'Y') printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}