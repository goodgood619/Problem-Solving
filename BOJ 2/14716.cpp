#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int i, j, x, y, n;
int arr[255][255];
int dr[8] = { 0,0,1,-1,1,-1,1,-1 };
int dc[8] = { 1,-1,0,0,1,-1,-1,1 };
int check[255][255];
int dfs(int r, int c) {
	int ret = 1;
	for (int k = 0; k < 8; k++){
		int nr = r + dr[k];
		int nc = c + dc[k];
		if (nr >= 0 && nr < x&&nc >= 0 && nc < y &&check[nr][nc] == 0 && arr[nr][nc] == 1) {
			check[nr][nc] = 1;
			ret += dfs(nr, nc);
		}
	}

	return ret;
}
int main() {
	scanf("%d %d", &x, &y);
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			scanf(" %d",&arr[i][j]);
		}
	}

	vector <int> v;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (check[i][j] == 0 && arr[i][j] == 1) {
				check[i][j] = 1;
				v.push_back(dfs(i, j));
			}
		}
	}
	printf("%d\n", v.size());
}