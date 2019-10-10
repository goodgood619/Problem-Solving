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
void dfs(int x,int y,vector<pair<int,int>> &v,int **visited,int n,int m,int **board) {

	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i],ny=y+goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny]==1 || board[nx][ny] == 0) continue;
		else if (visited[nx][ny] == -1) {
			visited[nx][ny] = 1;
			v.push_back({ nx,ny });
			dfs(nx, ny, v, visited, n, m, board);
		}
	}
}
void dfs2(int here,int n,int m,int x,int y,int dir,priority_queue<PPP,vector<PPP>,greater<PPP>> &pq,int dist,vector<vector<pair<int,int>>> &v2,int **board) {
	int nx = x + gox[dir], ny = y + goy[dir];
	if (nx<1 || nx>n || ny<1 || ny>m) return;
	if (board[nx][ny] == 0) dfs2(here,n, m, nx, ny, dir, pq, dist + 1, v2, board);
	else if (dist >= 2) {
		int find = -1;
		for (int i = 0; i < v2.size(); i++) {
			for (int j = 0; j < v2[i].size(); j++) {
				int hx = v2[i][j].first, hy = v2[i][j].second;
				if (hx == nx && hy == ny) {
					find = i;
					break;
				}
			}
			if (find != -1) break;
		}
		if (here != find && find!=-1) {
			pq.push({ dist,{here,find} });
		}
	}
}
int find(int parent[],int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent, parent[u]);
}
void uni(int u,int v,int child[]) {
	u = find(child,u), v = find(child,v);
	if (u == v) return;
	child[u] = v;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int** board = new int*[n + 1];
	for (int i = 1; i <= n; i++) board[i] = new int[m + 1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int** visited = new int* [n + 1];
	for (int i = 1; i <= n; i++) visited[i] = new int[m + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) visited[i][j] = -1;
	}
	vector<pair<int,int>> v;
	vector<vector<pair<int, int>>> v2;
	int area = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j] == -1 && board[i][j]==1) {
				visited[i][j] = 1;
				v.push_back({ i,j });
				dfs(i, j, v,visited,n,m,board);
				area++;
				v2.push_back(v);
				v.clear();
			}
		}
	}
	int needroad = area - 1;
	vector<pair<int, pair<int, int>>> graph;

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	for (int i = 0; i < v2.size(); i++) {
			for (int k = 0; k < v2[i].size(); k++) {
				int x = v2[i][k].first, y = v2[i][k].second;
				for (int q = 0; q < 4; q++) {
					dfs2(i,n,m,x, y, q, pq, 0,v2,board);
				}
		}
	}
	int* child = new int[area + 1];

	for (int i = 0; i <= area; i++) child[i] = i;
	int ans = 0,cnt=0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int here = pq.top().second.first;
		int next = pq.top().second.second;
		pq.pop();
		int heretop = find(child,here), nexttop = find(child,next);
		if (heretop != nexttop) {
			uni(here, next,child);
			ans += dist;
			cnt++;
		}
	}


	ans == 0  || cnt!=needroad? printf("-1") : printf("%d\n", ans);
	return 0;
}