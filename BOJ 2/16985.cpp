
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
#define mod 1000000009
#define lim 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[6][6][6];
int newboard[6][6][6];
int ans = 1e9;
vector<int> v;
void rotate(int num) { // 방향돌리기
	int new2board[6][6] = { 0, };
	for (int j = 1; j <= 5; j++) {
		for (int k = 1; k <= 5; k++) {
			new2board[k][6-j]=newboard[num][j][k];
		}
	}
	for (int j = 1; j <= 5; j++) {
		for (int k = 1; k <= 5; k++) {
			newboard[num][j][k] = new2board[j][k];
		}
	}
}
int bfs() { // 탐색
	bool visited[6][6][6] = { false, };
	queue<PPP> q;
	visited[1][1][1] = true;
	q.push({ { 1,1 }, { 1,0 } });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (x == 5 && y == 5 && z == 5) return cnt;
		for (int i = 0; i < 4; i++) {
			int ny = y + gox[i];
			int nz = z + goy[i];
			if (ny < 1 || ny>5 || nz < 1 || nz>5 || newboard[x][ny][nz] == 0 || visited[x][ny][nz]) continue;
			else if (!visited[x][ny][nz] && newboard[x][ny][nz]==1) {
				visited[x][ny][nz] = true;
				q.push({ { x,ny }, { nz,cnt + 1 } });
			}
		}
		for (int i = 1; i < 3; i++) {
			int nx = x + gox[i];
			if (nx < 1 || nx>5 || newboard[nx][y][z] == 0 || visited[nx][y][z]) continue;
			else if (!visited[nx][y][z] && newboard[nx][y][z]==1) {
				visited[nx][y][z] = true;
				q.push({ { nx,y }, { z,cnt + 1 } });
			}
		}
	}
	return 1e9;
}
void move() {// 돌리기
	for (int i = 0; i < 4; i++) {
		rotate(1);
		for (int j = 0; j < 4; j++) {
			rotate(2);
			for (int k = 0; k < 4; k++) {
				rotate(3);
				for (int l = 0; l < 4; l++) {
					rotate(4);
					for (int p = 0; p < 4; p++) {
						rotate(5);
						if (newboard[1][1][1] == 1 && newboard[5][5][5] == 1) {
							ans=min(ans,bfs());
						}
					}
				}
			}
		}
	}
}
int main(void) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int k = 1; k <= 5; k++) {
				scanf(" %d", &board[i][j][k]);
			}
		}
	}
	for (int i = 1; i <= 5; i++) {
		v.push_back(i);
	}
	do {
		move();
		memset(newboard, 0, sizeof(newboard));
		for (int i = 0; i < v.size(); i++) {
			for (int j = 1; j <= 5; j++) {
				for (int k = 1; k <= 5; k++) {
					newboard[i + 1][j][k] = board[v[i]][j][k]; // 새롭게 위치한 판을 만듬
				}
			}
		}
	} while (next_permutation(v.begin(), v.end()));
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}