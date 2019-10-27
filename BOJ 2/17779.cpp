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
bool visited[20][20];
int n;
struct pos {
	int x;
	int y;
};
void go1(int x,int y,int x1,int y1) {
	for (int i = x, j = y; i <= x1, j >= y1; i++, j--) visited[i][j] = true;
}
void go2(int x, int y, int x2, int y2) {
	for (int i = x, j = y; i <= x2, j <= y2; i++, j++) visited[i][j] = true;
}
void go3(int x1, int y1, int x3, int y3) {
	for (int i = x1, j = y1; i <= x3, j <= y3; i++, j++) visited[i][j] = true;
}
void go4(int x2, int y2,int x3, int y3) {
	for (int i = x2, j = y2; i <= x3, j >= y3; i++, j--) visited[i][j] = true;
}
void dfs5(int x,int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i], ny = y + goy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
		dfs5(nx, ny);
	}
}
int dfs(int x,int y,int tx,int ty,int **board) {
	visited[x][y] = true;
	int ret = board[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i],ny= y + goy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || nx == tx || ny == ty) continue;
		else ret += dfs(nx, ny, tx, ty,board);
	}
	return ret;
}
void go(int x,int y,int &ans,int **board) {
	for (int d1 = 1; d1 <= n; d1++) {
		for (int d2 = 1; d2 <= n; d2++) {
			int x1 = x + d1, y1 = y - d1, x2 = x + d2, y2 = y + d2, x3 = x + d1 + d2, y3 = y - d1 + d2;
			if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || x2 < 0 || x2 >= n ||y2<0 || y2>=n ||  x3 < 0 || x3 >= n|| y3<0 || y3>=n) continue;
			memset(visited, false, sizeof(visited));
			vector<int> temp;
			go1(x, y, x1, y1);
			go2(x, y, x2, y2);
			go3(x1, y1, x3, y3);
			go4(x2, y2, x3, y3);
			dfs5(x+1, y);
			int fivesum = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (visited[i][j]) fivesum += board[i][j];
				}
			}
			temp.push_back(dfs(0,0, x1, y+1,board));
			temp.push_back(dfs(0, n - 1, x2+1, y,board));
			temp.push_back(dfs(n - 1, 0, x1-1,y3,board));
			temp.push_back(dfs(n - 1, n - 1,x2,y3-1,board));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (!visited[i][j]) fivesum += board[i][j];
				}
			}
			temp.push_back(fivesum);
			sort(temp.begin(), temp.end());
			ans = min(ans, temp[4] - temp[0]);
		}
	}

}
int main() {
	int ans = 1e9;
	scanf("%d", &n);
	int **board = new int*[n];
	for (int i = 0; i < n; i++) board[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			go(i, j,ans,board);
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++) delete[] board[i];
	delete[] board;
	return 0;
}