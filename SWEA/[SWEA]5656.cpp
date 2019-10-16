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
typedef pair < int,int > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,w,h,ans=1e9;
vector<int> temp;
int board[16][16];
int Copy[16][16];
int choose(int x) {
	for (int i = 0; i < h; i++) {
		if (Copy[i][x] != 0) return i;
	}
	return -1;
}
void down() {
	for (int i = h - 1; i >= 0; i--) {
		for (int j = 0; j < w; j++) {
			if (Copy[i][j] != 0) continue;
			else {
				for (int k = i - 1; k >= 0; k--) {
					if (Copy[k][j] != 0) {
						Copy[i][j] = Copy[k][j];
						Copy[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}
void make(vector<int> temp) {
	memset(Copy, 0, sizeof(Copy));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			Copy[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		int shooty = temp[i];
		int shootx = choose(shooty);
		if (shootx == -1) continue; //그냥 없으니까
		bool visited[16][16] = {false,};
		queue<P> q;
		q.push({ shootx,shooty });
		visited[shootx][shooty] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int num = Copy[x][y];
			Copy[x][y] = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 1; j < num; j++) {
					int nx = x + j*gox[i];
					int ny = y + j*goy[i];
					if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny] || Copy[nx][ny] == 0) continue;
					else if (!visited[nx][ny]) {
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}

		down();
	}

	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cnt += (Copy[i][j] != 0);
		}
	}
	ans = min(ans, cnt);
}
void dfs(int index, int cnt, int depth) {
	if (cnt == depth) {
		make(temp);
		return;
	}
	for (int i = 0; i < w; i++) {
		temp.push_back(i);
		dfs(index + 1, cnt + 1, depth);
		temp.pop_back();
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {	
		scanf("%d%d%d", &n, &w, &h);
		memset(board, 0, sizeof(board));
		ans = 1e9;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		dfs(0, 0, n);
		printf("#%d %d\n", Case++, ans);
	}
	return 0;
}