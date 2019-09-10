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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,ans;
vector<vector<int>> a;
bool visited[101];
void dfs(int here) {
	visited[here] = true;
	ans++;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[second].push_back(first);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		ans = 0;
		dfs(i);
		if (ans == n) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}