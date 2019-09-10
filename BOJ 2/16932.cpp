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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int board[1005][1005];
int check[1005][1005];
int area[1000005];
bool visited[1005][1005];
int dfs(int x, int y, int num) {

	visited[x][y] = true;
	int ret = 1;
	check[x][y] = num;
	for (int i = 0; i < 4;i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == 0) continue;
		if (!visited[nx][ny]) {
			visited[nx][ny] = true;
			ret += dfs(nx, ny, num);
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int num = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && board[i][j] == 1) {
				int cnt=dfs(i, j, num);
				area[num] = cnt;
				num++;
			}
		}
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 0) {
				int sum = 1;
				map<int, int> mm;
				for (int k = 0; k < 4; k++) {
					int nx = i + gox[k];
					int ny = j + goy[k];
					if (board[nx][ny] == 0 || mm.count(check[nx][ny])==1) continue;
					mm[check[nx][ny]] = 1;
					sum += area[check[nx][ny]];
				}
				Max = max(Max, sum);
			}
		}
	}
	printf("%d\n", Max);
	return 0;
}