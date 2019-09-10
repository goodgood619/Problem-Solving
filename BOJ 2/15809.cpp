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
typedef pair<int, pair<ll, char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
int army[100005];
int parent[100005];
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &army[i]);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++) {
		int what, first, second;
		scanf("%d%d%d", &what, &first, &second);
		if (what == 1) {
			first = find(first);
			uni(first, second);
			int firsttop = find(first);
			army[firsttop] += army[first];
			army[first] = 0;
		}
		else {
			int firsttop = find(first);
			int secondtop = find(second);
			if (army[firsttop] == army[secondtop]) {
				army[firsttop] = 0;
				army[secondtop] = 0;
			}
			else if(army[firsttop]<army[secondtop]){
			
				army[secondtop] -= army[firsttop];
				army[firsttop] = 0;
				uni(firsttop, secondtop);
			}
			else if (army[firsttop] > army[secondtop]) {
				
				army[firsttop] -= army[secondtop];
				army[secondtop] = 0;
				uni(secondtop, firsttop);
			}
		}
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (army[i] == 0) continue;
		v.push_back(army[i]);
	}
	printf("%d\n", v.size());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}
