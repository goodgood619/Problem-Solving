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
vector<vector<P>> a;
int par[100005][18];
int d[100005];
bool visited[100005];
int mindist[100005][18]; //현위치에서 2^j 번째부모까지의 거리중에 최소값
int maxdist[100005][18]; // 현위치에서 2^j번째부모까지의 거리중에 최대값
void make() { //요거잘하기
	for (int j = 1; j <= 17; j++) {
		for (int i = 1; i <= n; i++) {
			mindist[i][j] = min(mindist[i][j-1], mindist[par[i][j - 1]][j - 1]); //이거맞는지를 모르겠네
			maxdist[i][j] = max(maxdist[i][j-1], maxdist[par[i][j - 1]][j - 1]); // 아래동일
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}
void dfs(int here, int parent,int depth) {
	visited[here] = true;
	d[here] = depth;
	par[here][0] = parent;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i].first;
		int nextcost = a[here][i].second;
		if (!visited[next]) {
			dfs(next, here, depth + 1);
			mindist[next][0] = min(mindist[next][0], nextcost);
			maxdist[next][0] = max(maxdist[next][0], nextcost);
		}
	}
}
P lca(int a, int b) {
	int maxcost = -1;
	int mincost = 1e9;
	// 깊이가 맞는지부터 확인,근데 보통 같지 않고, 같아도 어차피 걔바로위가 공통조상일지 모름 ㅇㅇ
	if (d[a] > d[b]) swap(a, b); //우선 a보다 b가 무조건 깊이가 깊다고 몰빵 ㄱ
	//b의 depth를 끌어올리기
	for (int i = 17; i >= 0; i--) {
		if (d[b] - d[a] >=(1 << i)) {    // if((d[b]-d[a]) &(1<<i)!=0) 이런것도 있다
			maxcost = max(maxcost, maxdist[b][i]);//갱신하고 가야지(중간을 확인을 못하고 넘어가는경우가 생김)
			mincost = min(mincost, mindist[b][i]);
			b = par[b][i];
		}
	}
	if (a == b) return {mincost,maxcost}; // 깊이는 같은데, 만약에 그냥 같아버리면 더이상 올라갈 필요 없으니 ㄱ
	for (int i = 17; i >= 0;i--) { //깊이를 음, 바로직전까지만 올리자, 즉 부모가 다를때만 올리자 계속
		if (par[a][i] != par[b][i]) {
			maxcost = max(maxcost, max(maxdist[a][i],maxdist[b][i]));
			mincost = min(mincost, min(mindist[a][i], mindist[b][i]));
			a = par[a][i];
			b = par[b][i];
		}
	}
	maxcost = max(maxcost, max(maxdist[a][0], maxdist[b][0]));
	mincost = min(mincost, min(mindist[a][0], mindist[b][0]));
	return { mincost,maxcost };
}

int main() {
	scanf("%d", &n);
	a.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 17; j++) {
			mindist[i][j] = 1e9; //초기화깜박
		}
	}
	for (int i = 1; i < n; i++) {
		int first, second,cost;
		scanf("%d%d%d", &first, &second,&cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	dfs(1, 0,0);
	make();

	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		P ans = lca(first, second);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}