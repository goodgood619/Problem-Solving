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
int n, m, t;
bool visited[51][50];
struct position {
	int num;
	int dir;
	int numcnt;
};
struct pos {
	int x;
	int y;
};
void dfs(int x,int y,int num,vector<pos> &erase,int **board) {
	visited[x][y] = true;
	erase.push_back({ x,y });
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i], ny = y + goy[i];
		if (ny < 0) ny = m - 1;
		if (ny >= m) ny = 0;
		if (nx<1 || nx>n || visited[nx][ny] || board[nx][ny] != num) continue;
		else if (!visited[nx][ny] && board[nx][ny] == num) {
			dfs(nx, ny, board[nx][ny],erase,board);
		}
	}
}
void go2(int rotatenum,int dir,int numcnt,int **board) {
	for (int i = 1; i <= numcnt; i++) {
		//시계
		if (dir == 0) {
			queue<int> q;
			for (int j = 0; j < m; j++) {
				q.push(board[rotatenum][j]);
			}
			int idx = 1;
			while (!q.empty()) {
				int here = q.front();
				q.pop();
				board[rotatenum][idx] = here;
				idx++;
				idx %= m;
			}
		}
		else { //반시계
			queue<int> q;
			q.push(board[rotatenum][0]);
			for (int j = m - 1; j > 0; j--) q.push(board[rotatenum][j]);
			int idx = m - 1;
			while (!q.empty()) {
				int here = q.front();
				q.pop();
				board[rotatenum][idx] = here;
				idx--;
			}
			
		}
	}
}
void go(vector<position> &v,int **board) {
	for (int i = 0; i < v.size(); i++) {
		int num = v[i].num, dir = v[i].dir, numcnt = v[i].numcnt;
		vector<int> temp;
		memset(visited, false, sizeof(visited));
		for (int j = 1; j <= n; j++) {
			if (j % num == 0) temp.push_back(j);
		}
		//rotate
		for (int j = 0; j < temp.size(); j++) {
			go2(temp[j], dir, numcnt,board);
		}

		vector<pos> erase;
		vector<vector<pos>> realerase;
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < m; k++) {
				if (!visited[j][k] && board[j][k] != 0) {
					dfs(j, k, board[j][k],erase,board);
					if (erase.size() >= 2) realerase.push_back(erase);
					erase.clear();
				}
			}
		}

		if (realerase.size() >= 1) {
			for (int j = 0; j < realerase.size(); j++) {
				for (int k = 0; k < realerase[j].size(); k++) {
					int x = realerase[j][k].x, y = realerase[j][k].y;
					board[x][y] = 0;
				}
			}
		}
		else {
			double total = 0, averagecnt = 0;
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < m; k++) {
					if (board[j][k] == 0) continue;
					averagecnt++;
					total += board[j][k];
				}
			}
			if(averagecnt>0) total /= averagecnt;
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < m; k++) {
					if (board[j][k] == 0) continue;
					if (total > board[j][k]) board[j][k]++;
					else if (total < board[j][k]) board[j][k]--;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &t);
	vector<position> v;
	int** board = new int*[n + 1];
	for (int i = 1; i <= n; i++) board[i] = new int[m];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int i = 0; i < t; i++) {
		int a, b, c;
		scanf(" %d%d%d", &a, &b, &c);
		v.push_back({ a,b,c });
	}

	go(v,board);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			ans += board[i][j];
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) delete[] board[i];
	delete[] board;
	v.clear();
	return 0;
}