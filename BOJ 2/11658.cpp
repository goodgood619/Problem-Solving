#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> seg;
int board[1026][1026];
int n, m;
int h = 1;
void update(int x, int y, int value) {
	int j = y + h - 1;
	int i = x + h - 1;
	seg[i][j] = value;
	while (j > 1) {
		j /= 2;
		seg[i][j] = seg[i][j * 2] + seg[i][j * 2 + 1];
	}
	while (i > 1) {
		j = y + h - 1;
		i /= 2;
		seg[i][j] = seg[i * 2][j] + seg[i * 2 + 1][j];
		while (j > 1) {
			j /= 2;
			seg[i][j] = seg[i][j * 2] + seg[i][j * 2 + 1];
		}
	}
	return;
}
int yquery(int x,int nodenum,int left,int right,int nodeleft,int noderight){
	if (nodeleft > right || noderight < left) return 0;
	else if (left <= nodeleft && noderight <= right) return seg[x][nodenum];
	int mid = (nodeleft + noderight) / 2;
	return yquery(x,nodenum * 2, left, right, nodeleft, mid) + yquery(x,nodenum * 2 + 1, left, right, mid + 1, noderight);
}
int xquery(int nodenum, int left, int right, int nodeleft, int noderight, int y1, int y2) {
	if (nodeleft > right || noderight < left) return 0;
	else if (left <= nodeleft && noderight <= right) return yquery(nodenum, 1, y1, y2, 1, h);
	int mid = (nodeleft + noderight) / 2;
	return xquery(nodenum * 2, left, right, nodeleft, mid, y1, y2) + xquery(nodenum * 2 + 1, left, right, mid + 1, noderight, y1, y2);
}
int main() {
	scanf("%d%d", &n, &m);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 0; i < h * 2; i++) { seg[i].resize(h * 2); }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
			update(i, j, board[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		int what;
		scanf("%d", &what);
		if (what == 0) {
			int x1, y1, value;
			scanf("%d%d%d", &x1, &y1, &value);
			update(x1, y1, value);
		}
		else {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			int ans=xquery(1, x1, x2, 1, h, y1, y2);
			printf("%d\n", ans);
		}
	}
	return 0;
}