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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int goz[2] = { 1,-1 };
int t, Case = 1,m,n,h,zero;
int tomato[101][101][101];
bool visited[101][101][101];
queue<PPPP> q;
int bfs() {
	int Max = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second.first;
		int cnt = q.front().second.second;
		Max = max(Max, cnt);
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + gox[i];
			int nz = z + goy[i];
			if (ny<1 || ny>n || nz<1 || nz>m || visited[x][ny][nz] || tomato[x][ny][nz]==-1) continue;
			else if (!visited[x][ny][nz] && tomato[x][ny][nz] == 0) {
				visited[x][ny][nz] = true;
				tomato[x][ny][nz] = 1;
				q.push({ { x,ny }, { nz,cnt + 1 } });
			}
		}
		for (int i = 0; i < 2; i++) {
			int nx = x + goz[i];
			if (nx<1 || nx>h || visited[nx][y][z] || tomato[nx][y][z] == -1) continue;
			else if (!visited[nx][y][z] && tomato[nx][y][z] == 0) {
				visited[nx][y][z] = true;
				tomato[nx][y][z] = 1;
				q.push({ { nx,y }, { z,cnt + 1 } });
			}
		}
	}
	return Max;
}
int main() {
	scanf("%d%d%d", &m, &n, &h);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				scanf(" %d", &tomato[i][j][k]);
				if (tomato[i][j][k] == 1) {
					q.push({ { i,j }, { k,0 }});
					zero++;
					visited[i][j][k] = true;
				}
				else if (tomato[i][j][k] == -1) zero++;
			}
		}
	}
	if (zero == n * m*h) printf("0\n");
	else {
		int ans=bfs();
		int no = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= m; k++) {
					if (tomato[i][j][k]==0) {
						no = 1;
					}
				}
			}
		}
		no == 1 ? printf("-1\n") : printf("%d\n", ans);
	}
	return 0;
}