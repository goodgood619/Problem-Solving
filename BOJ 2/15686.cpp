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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m,ans=1e9;
int board[51][51];
bool visited[14];
vector<pair<int, int>> v,temp,home;
void dfs(int index,int cnt,int depth) {
	if (cnt == depth) {
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int dist = 1e9;
			for (int j = 0; j < temp.size(); j++) {
				dist = min(dist, abs(home[i].first - temp[j].first) + abs(home[i].second - temp[j].second));
			}
			sum += dist;
		}
		ans = min(ans, sum);
		return;
	}

	for (int i = index; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			dfs(i + 1, cnt + 1, depth);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 2) v.push_back({ i,j });
			if (board[i][j] == 1) home.push_back({ i,j });
		}
	}
	dfs(0,0, m);
	printf("%d\n", ans);
	return 0;
}