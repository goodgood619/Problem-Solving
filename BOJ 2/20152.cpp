#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int gox[2] = { 0,1 };
int goy[2] = { 1,0 };
long long goPcRoom(int x, int y, int ex, int ey, vector<vector<long long>>& board, vector<vector<long long>>& dp, int curDist, int dist) {
	if (x == ex && y == ey) {
		if (curDist <= dist) return 1;
		else return 0;
	}
	long long& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 2; i++) {
		int nx = x + gox[i], ny = y + goy[i];
		if (nx < 0 || nx >= ex + 1 || ny < 0 || ny >= ey + 1 || board[nx][ny] == 1) continue;
		ret += goPcRoom(nx, ny, ex, ey, board, dp, curDist + 1, dist);
	}
	return ret;
}
int main() {
	vector<vector<long long>> board;
	vector<vector<long long>> dp;
	int h, n;
	scanf("%d%d", &h, &n);
	if (h > n) {
		int temp = h;
		h = n;
		n = temp;
	}
	board.assign(n + 1, vector<long long>(n + 1, 0));
	dp.assign(n + 1, vector<long long>(n + 1, -1));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i < j) board[i][j] = 1;
		}
	}
	printf("%lld\n", goPcRoom(h, h, n, n, board, dp, 0, abs(h - n) + abs(h - n)));
	return 0;
}