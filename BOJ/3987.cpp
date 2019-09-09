#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
char board[505][505];
int n, m,sx,sy;
bool visited[505][505][4];
// 
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first != b.first) return a.first > b.first;
	if (a.second != b.second) return a.second < b.second;
}

P go(int x, int y, int dir) {
	visited[x][y][dir] = true;
	int cnt = 1;
	int p = dir;
	while (1) {
		int nx = x + gox[dir];
		int ny = y + goy[dir];
		if (visited[nx][ny][dir]) return { 1e9,p };
		if (nx<1 || nx>n || ny<1 || ny>m || board[nx][ny] == 'C') return { cnt,p };
		if (board[nx][ny] == '/') {
			// 0 / 1
			// 1 / 0
			// 2 / 3
			// 3 / 2
			x = nx, y = ny;
			cnt++;
			visited[nx][ny][dir] = true;
			if (dir == 0 || dir == 1) {
				dir = 1 - dir;
			}
			else if (dir == 2 || dir == 3) {
				dir = 5 - dir;
			}
		}
		else if(board[nx][ny]=='.'){
			cnt++;
			x = nx,y=ny;
			visited[nx][ny][dir] = true;
		}
		else {
			// 북동남서, 0 3, 1 2, 2 1, 3 0
			x = nx, y = ny;
			cnt++;
			visited[nx][ny][dir] = true;
			dir = 3 - dir;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	scanf("%d%d", &sx, &sy);
	int ans = 0;
	vector<P> v;
	for (int i = 0; i < 4; i++) {
		memset(visited, false, sizeof(visited));
		v.push_back(go(sx, sy, i));
	}
	sort(v.begin(), v.end(), compare);
	if (v[0].first == 1e9) {
		// URDL순서()
		if (v[0].second == 0) printf("U\n");
		else if (v[0].second == 1) printf("R\n");
		else if (v[0].second == 2) printf("D\n");
		else printf("L\n");
		printf("Voyager\n");
	}
	else {
		if (v[0].second == 0) printf("U\n");
		else if (v[0].second == 1) printf("R\n");
		else if (v[0].second == 2) printf("D\n");
		else printf("L\n");
		printf("%d\n", v[0].first);
	}
 	return 0;
}