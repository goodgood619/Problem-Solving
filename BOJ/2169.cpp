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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[3] = { 1,0,0 };
int goy[3] = { 0,-1,1};
int n, m;
int dp[1005][1005][3];
int board[1005][1005];
bool visited[1005][1005];
int go(int x, int y,int pos) {
	if (visited[x][y] && x<=0 || x>n || y<=0 ||y>m) {
		return -1e9;
	}
	if (x == n && y == m) {
		return dp[x][y][pos]=board[x][y];
	}
	int &ret = dp[x][y][pos];
	if (ret != -1) return ret;
	ret = -1e9;
	visited[x][y] = true; //하이라이트
	int nx = x + gox[pos];
	int ny = y + goy[pos];
	if (pos == 0) { //아래
		ret = max(ret, max(go(x+1,y, 0) + board[x][y], max(go(x+1,y,1) + board[x][y], go(x+1, ny,2) + board[x][y])));
	}
	else if (pos == 1) { //왼쪽진행
		ret = max(ret, max(go(x,y-1, 1) + board[x][y], go(x,y-1,0) + board[x][y]));
	}
	else { //오른쪽진행
		ret = max(ret, max(go(x, y+1, 2) + board[x][y], go(x,y+1,0) + board[x][y]));
	}
	visited[x][y] = false;
	return ret;
}
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n",max(go(1, 1,0),go(1,1,2))); //아래로 가느냐, 오른쪽으로 가느냐
	return 0;
}