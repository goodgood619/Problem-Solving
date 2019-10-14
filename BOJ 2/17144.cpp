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
int gox[4] = {0,-1,0,1 };
int goy[4] = { 1,0,-1,0 };
struct position {
	int x;
	int y;
};
void upclean(int cx,int cy,int r,int c,int **board) {
	int x = cx, y = cy, rs = 0, cs = 0;
	int top = board[x][y];
	for (int i = x; i > 0; i--) {
		board[i][cy] = board[i - 1][cy];
	}
	for (int j = cy; j < c - 1; j++) {
		board[0][j] = board[0][j + 1];
	}
	for (int i = 0; i < cx; i++) {
		board[i][c - 1] = board[i + 1][c - 1];
	}
	for (int j = c - 1; j > 1; j--) {
		board[cx][j] = board[cx][j - 1];
	}
	board[cx][1] = 0;
	board[cx][cy] = -1;
}
void downclean(int cx2, int cy2,int r,int c,int **board) {
	int x = cx2, y = cy2, rs = 0, cs = 0;
	int top = board[cx2][cy2];
	for (int i = x; i < r-1; i++) {
		board[i][cy2] = board[i + 1][cy2];
	}
	for (int j = cy2; j < c - 1;j++) {
		board[r - 1][j] = board[r - 1][j + 1];
	}
	for (int i = r - 1;i>cx2; i--) {
		board[i][c - 1] = board[i - 1][c - 1];
	}
	for (int j = c - 1; j > 1;j--) {
		board[cx2][j] = board[cx2][j - 1];
	}
	board[cx2][1] = 0;
	board[cx2][cy2] = -1;
}
void bfs(int r,int c,int cx,int cy,int cx2,int cy2,int t,int** board) {
	for (int i = 1; i <= t; i++) {
		int** tempboard = new int* [r];
		for (int j = 0; j < r; j++) {
			tempboard[j] = new int[c];
		}
		queue<position> q;
		map<pair<int,int>, int> cnt;
		for (int k = 0; k < r; k++) {
			for (int p = 0; p < c; p++) {
				tempboard[k][p] = 0;
				if (board[k][p] > 0) {
					q.push({ k,p });
				}
			}
		}
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i], ny = y + goy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] == -1) continue;
				else {
					tempboard[nx][ny] += (board[x][y] / 5);
					cnt[{x, y}]++;
				}
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				board[i][j] = board[i][j] - board[i][j] / 5 * cnt[{i, j}];
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (tempboard[i][j] == -1) continue;
				board[i][j] += tempboard[i][j];
			}
		}
		upclean(cx,cy,r,c,board);
		downclean(cx2, cy2,r,c, board);
		for (int j = 0; j < r; j++) delete[] tempboard[j];
		delete[] tempboard;
	}
}
int main() {
	int r, c, t;
	scanf("%d%d%d", &r, &c, &t);
	int** board = new int* [r];
	for (int i = 0; i < r; i++) board[i] = new int[c];
	int cx = -1, cy = -1,cx2=-1,cy2=-1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == -1 && cx==-1) {
				cx = i, cy = j;
			}
			else if (board[i][j] == -1 && cx != -1) {
				cx2 = i;
				cy2 = j;
			}
		}
	}

	bfs(r,c,cx, cy, cx2, cy2,t, board);
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == -1) continue;
			ans += board[i][j];
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < r; i++) delete[] board[i];
	delete[] board;
	return 0;
}