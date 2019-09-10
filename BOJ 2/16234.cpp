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
int gox[4] = { 0, -1,0,1};
int goy[4] = { 1, 0,-1,0};
int board[51][51];
bool visited[51][51];
int temp[51][51];
int n, l, r;
void dfs(int x,int y,int num) {
	temp[x][y] = num;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny] || abs(board[x][y] - board[nx][ny]) < l || abs(board[x][y] - board[nx][ny]) > r) continue;
		dfs(nx, ny, num);
	}
}
int main() {
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int ti = 0;
	while (1) {
		memset(visited, false, sizeof(visited));
		memset(temp, 0, sizeof(temp));
		int cnt = 0;
		int num = 1;
		vector<vector<P>> v;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visited[i][j]) {
					dfs(i, j,num);
					cnt++,num++;
				}
			}
		}
		if (cnt == n * n) break;
		v.resize(num);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[temp[i][j]].push_back({i,j});
			}
		}

		for (int i = 1; i <num; i++) {
			int sum = 0;
			vector<P> change;
			for (int j = 0; j < v[i].size(); j++) {
				sum += board[v[i][j].first][v[i][j].second];
				change.push_back({ v[i][j].first,v[i][j].second });
			}
			sum /= v[i].size();
			for (int i = 0; i < change.size(); i++) {
				board[change[i].first][change[i].second] = sum;
			}
		}
		ti++;
	}
	printf("%d\n",ti);
	return 0;
}