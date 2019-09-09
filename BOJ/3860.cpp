
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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, k, hole;
int dist[905];
int board[35][35];
vector<vector<P>> a;
struct h {
	int x1, y1, x2, y2, cost;
};
vector<h> v;
int ok(int x, int y) {
	for (int i = 0; i < v.size(); i++) {
		if (x == v[i].x1 && y == v[i].y1) {
			return 0;
		}
	}
	return 1;
}
int main() {
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		memset(board, 0, sizeof(board));
		memset(dist, 0, sizeof(dist));
		a.clear();
		v.clear();
		a.resize(n*m + 1);
		int cnt = 1;
		int en = n*m - 1;
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			board[first][second] = 1;
		}
		scanf("%d", &hole);
		for (int i = 1; i <= hole; i++) {
			int x1, x2, y1, y2, cost;
			scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &cost);
			v.push_back({ x1,y1,x2,y2,cost });
		}

		for (int j = 0; j <m; j++) {
			for (int i = 0; i <n; i++) {
				if (board[i][j] == 1 || (i == n - 1 && j == m - 1) || !ok(i, j)) continue; //묘비이거나, 끝점이거나, 구멍일때
				else {
					for (int k = 0; k < 4; k++) { //잔디 4방향
						int nx = i + gox[k];
						int ny = j + goy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위피하기
						if (board[nx][ny] == 1) continue; //묘비피하기
						int next = ny*n + nx;
						int here = j*n + i;
						a[here].push_back({ next,1 });
					}
				}
			}
		}
		// 구멍에서 연결되는 곳 만들기
		for (int i = 0; i < v.size(); i++) {
			int x1 = v[i].x1, x2 = v[i].x2, y1 = v[i].y1, y2 = v[i].y2, cost = v[i].cost;
			int here = y1*n + x1;
			int next = y2*n + x2;
			a[here].push_back({ next,cost });
		}
		for (int i = 0; i <= n*m - 1; i++) dist[i] = 1e9;
		dist[0] = 0;
		int cycle = 0;
		int check = 0;
		for (int k = 0; k < n*m; k++) {
			for (int i = 0; i <= n*m-1; i++) {
				if (a[i].size() == 0) continue;
				for (int j = 0; j < a[i].size(); j++) {
					int next = a[i][j].first;
					int nextcost = a[i][j].second;
					if (dist[next] > dist[i] + nextcost && dist[i] != 1e9) {
						if (k == n*m - 1) cycle = 1;
						dist[next] = dist[i] + nextcost;
					}
				}
			}
		}
		if (cycle) printf("Never\n");
		else if (dist[en] == 1e9) printf("Impossible\n");
		else printf("%d\n", dist[en]);
	}
	return 0;
}