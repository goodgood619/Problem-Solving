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
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {-1,0,1,0 };
int goy[4] = {0,1,0,-1 };
int n;
int board[17][17];
// 0: 가로, 1:세로,2:대각선
// 최초의 모양은 가로모양이므로 0
int dfs(int sx, int sy, int ex, int ey, int flag) {
	if (ex == n && ey == n) return 1;
	int ret = 0;
	if (flag == 0) { // 지금 현재 가로모양
		if (ex <= n && ey + 1 <= n && board[ex][ey + 1] != 1) { // 다음 가로모양 가능한지 판별
			ret += dfs(ex, ey, ex, ey + 1, 0);
		}
		if (ex + 1 <= n && ey + 1 <= n && board[ex + 1][ey + 1] != 1 && board[ex][ey + 1] != 1 && board[ex + 1][ey] != 1) { // 다음 대각선 모양 가능한지 판별
			ret += dfs(ex, ey, ex + 1, ey + 1, 2);
		}
	}
	else if (flag == 1) { // 지금 현재 세로모양
		if (ex+1 <= n && ey <= n && board[ex+1][ey] != 1) { // 다음 세로모양 가능한지 판별
			ret += dfs(ex, ey, ex+1, ey, 1);
		}
		if (ex + 1 <= n && ey + 1 <= n && board[ex + 1][ey + 1] != 1 && board[ex][ey + 1] != 1 && board[ex + 1][ey] != 1) { //다음 대각선 모양 가능한지 판별
			ret += dfs(ex, ey, ex + 1, ey + 1, 2);
		}
	}
	else { // 지금 현재 대각선모양
		if (ex <= n && ey + 1 <= n && board[ex][ey + 1] != 1) { // 다음 가로모양
			ret += dfs(ex, ey, ex, ey + 1, 0);
		}
		if (ex + 1 <= n && ey <= n && board[ex + 1][ey] != 1) { // 다음 세로모양
			ret += dfs(ex, ey, ex + 1, ey, 1);
		}
		if (ex + 1 <= n && ey + 1 <= n && board[ex + 1][ey + 1] != 1 && board[ex][ey + 1] != 1 && board[ex + 1][ey] != 1) { // 다음 대각선모양
			ret += dfs(ex, ey, ex + 1, ey + 1, 2);
		}
	}
	return ret;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	printf("%d\n", dfs(1, 1, 1, 2,0));
	return 0;
}