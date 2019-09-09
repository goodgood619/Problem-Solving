
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
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int rx[3] = {0,-1,1};
int ry[3] = {1,1,1};
char board[15][100005];
int time[100005];
int ans[100005];
int n;
int dfs(int x, int y) {
	if (board[x][y] == 'X') return 0;
	if (y == n-1) return 1;
	board[x][y] = 'X';
	if (x == 10) { //땅바닥
		if (dfs(x, y + 1)) return 1;
		if (dfs(x - 1, y + 1)) { //부스터 쓰기
			time[y] = 1; // y에서 부스터를 썼다는 의미
			return 1;
		}
	}
	else if (x == 1) { // 공중에서 천장
		if (dfs(x + 1, y + 1)) return 1;
		if (dfs(x, y + 1)) {
			time[y] = 1;
			return 1;
		}
	}
	else { //공중
		if (dfs(x + 1, y + 1)) return 1; //땅바닥으로
		if (dfs(x - 1, y + 1)) { //계속 공중으로
			time[y] = 1;
			return 1;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}
	dfs(10, 0);
	int Size = 0;
	for (int i = 0; i < n; i++) { // 가로시점 y에서 기록된 시간이 존재한다면, 걔는 지금 날고있는중임!!
		int curtime = i;
		int cnt = 0;
		if (time[i]) Size++;
		while (time[i] == 1) {
			cnt++;
			i++;
		}
		ans[curtime] = cnt;
	}
	printf("%d\n", Size);
	for (int i = 0; i < n; i++) {
		if(ans[i]) printf("%d %d\n", i, ans[i]);
	}
	return 0;
}