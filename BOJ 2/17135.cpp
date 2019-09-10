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
#define mod 1000000009
//typedef pair<int, int> P;
//typedef pair<pair<int,int>,int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1, -1,0 };
int goy[4] = { 1,0, 0,-1 };
int n, m, d,ans;
int board[17][17];
int Copy[17][17];
bool visited[17];
struct P{
	int x, y;
};
struct PP {
	int dist, x, y;
};
vector<P> v, temp;
bool compare(const PP &a,const PP &b) {
	if (a.dist != b.dist) return a.dist < b.dist;
	if (a.y != b.y) return a.y < b.y;
	if (a.x != b.x) return a.x < b.x;
}
P bfs(int x,int y,int d) {
	vector<PP> ttt;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (Copy[i][j] == 1) {
				int dist = abs(x - i) + abs(y - j);
				if (dist > d) continue;
				ttt.push_back({dist,i,j});
			}
		}
	}
	if (ttt.size() == 0) return { 0,0 };
	else {
		sort(ttt.begin(), ttt.end(), compare);
		return {ttt[0].x, ttt[0].y};
	}
}
bool check() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (Copy[i][j] == 1) return false;
		}
	}
	return true;
}
void down() {
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			Copy[i + 1][j] = Copy[i][j];
			if (i + 1 > n) Copy[i + 1][j] = 0;
			if(Copy[i][j]==1) Copy[i][j] = 0;
		}
	}
}
void dfs(int index,int cnt,int depth) {
	if (cnt == depth) {
		memset(Copy, 0, sizeof(Copy));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				Copy[i][j] = board[i][j];
			}
		}
		int cnt2 = 0;
		while (1) {
			bool attacked[17][17] = { false, };
			for (int i = 0; i < temp.size(); i++) {
				P p = bfs(temp[i].x, temp[i].y, d);
				if (p.x == 0) continue;
				else {
					attacked[p.x][p.y] = true;
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (attacked[i][j]) {
						cnt2++;
						Copy[i][j] = 0;
					}
				}
			}
			down();
			if (check()) break;
		}
		ans = max(ans, cnt2);
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
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int j = 1; j <= m; j++) {
		v.push_back({ n + 1,j });
	}
	dfs(0, 0, 3);
	printf("%d\n", ans);
	return 0;
}