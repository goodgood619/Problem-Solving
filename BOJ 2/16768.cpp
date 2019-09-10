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
int t, Case = 1,n,k;
int board[101][11];
bool visited[101][11];
vector<pair<int, int>> v;
int bfs(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int Max = 1;
	v.push_back({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny < 1 || ny>10 || board[nx][ny] != num || visited[nx][ny] || board[nx][ny]==0) continue;
			else if (!visited[nx][ny] && board[nx][ny] == num) {
				q.push({ nx,ny });
				Max++;
				visited[nx][ny] = true;
				v.push_back({ nx,ny });
			}
 		}
	}
	return Max;
}
void remove() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		board[x][y] = 0;
	}
}
void down() {
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= 10; j++) {
			if (board[i][j] == 0) {
					for (int k = i - 1; k >= 1; k--) {
						if (board[k][j] != 0) {
							board[i][j] = board[k][j];
							board[k][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
int main() {
	scanf(" %d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf(" %1d", &board[i][j]);
		}
	}

	while (true) {
		bool ok = false;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 10; j++) {
				if (board[i][j] != 0 && !visited[i][j]) {
					v.clear();
					int a = bfs(i, j,board[i][j]);
					if (a >= k) {
						ok = true;
						remove();
						//down();
						v.clear();
					}
					else v.clear();
				}
			}
		}

		down();
		if (!ok) break;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			printf("%d", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}