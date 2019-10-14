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
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
struct position {
	int t;
	int p;
};
void go(int here,vector<position> &v,int* visited,int n,int &ans,int earn) {
	if (here >= n) {
		if (here == n) ans = max(ans, earn);
		return;
	}
	ans = max(ans, earn);
	if (here + v[here].t <= n) {
		go(here + v[here].t, v, visited, n, ans, earn + v[here].p);
	}
	else go(here + 1, v, visited, n, ans, earn);
	go(here + 1, v, visited, n, ans, earn);
}
int main() {
	int n;
	scanf("%d", &n);
	int ans = 0, earn=0;
	vector<position> v;
	int* visited = new int[n + 1];
	for (int i = 0; i <= n; i++) visited[i] = 0;
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf(" %d%d", &a, &b);
		v.push_back({ a,b });
	}
	go(0, v, visited,n,ans,earn);
	printf("%d\n", ans);
	return 0;
}