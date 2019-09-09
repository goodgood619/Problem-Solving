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
int t, Case = 1,ans;
char board[5][5];
bool visited[5][5];
void dfs(int here,int cnt) {
	if (here >= 25) return;
	if (cnt == 7) {
		queue<P> q;
		int yes = 0;
		int check[5][5] = { 0, };
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (visited[i][j]) {
					check[i][j] = 1;
					q.push({ i,j });
					yes = 1;
					break;
				}
			}
			if (yes) break;
		}
		int cnt = 1;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || !visited[nx][ny] || check[nx][ny]) continue;
				else if (visited[nx][ny]) {
					check[nx][ny] = 1;
					cnt++;
					q.push({ nx,ny });
				}
			}
		}
		if (cnt < 7) return;
		int s = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (visited[i][j]) {
					if (board[i][j] == 'S') s++;
				}
			}
		}
		if (s >= 4) ans++;
		return;
	}
	while (visited[here / 5][here % 5]) here++;
	visited[here / 5][here % 5] = true;
	dfs(here, cnt + 1);
	visited[here / 5][here % 5] = false;
	dfs(here + 1, cnt);
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	dfs(0,0);
	printf("%d\n", ans);
	return 0;
}