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
vector<vector<int>> a;
int par[100005][18];
int d[100005];
bool visited[100005];
void make() { //요거잘하기
	for (int j = 1; j <= 17; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}
void dfs(int here, int parent,int depth) {
	visited[here] = true;
	d[here] = depth;
	par[here][0] = parent;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next, here, depth + 1);
		}
	}
}
int lca(int a, int b) {
	// 깊이가 맞는지부터 확인,근데 보통 같지 않고, 같아도 어차피 걔바로위가 공통조상일지 모름 ㅇㅇ
	if (d[a] > d[b]) swap(a, b); //우선 a보다 b가 무조건 깊이가 깊다고 몰빵 ㄱ
	//b의 depth를 끌어올리기
	for (int i = 17; i >= 0; i--) {
		if (d[b] - d[a] >=(1 << i)) {
			b = par[b][i];
		}
	}
	if (a == b) return a; // 깊이는 같은데, 만약에 그냥 같아버리면 더이상 올라갈 필요 없으니 ㄱ
	for (int i = 17; i >= 0;i--) { //깊이를 음, 바로직전까지만 올리자, 즉 부모가 다를때만 올리자 계속
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	dfs(1, 0,0);
	make();

	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		printf("%d\n",lca(first, second));
	}
	return 0;
}