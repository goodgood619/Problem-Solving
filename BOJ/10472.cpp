#include <stdio.h>
#include <algorithm>
using namespace std;

int t; 
char c[5][5];
int gox[5] = {0,1,-1,0,0};
int goy[5] = {0,0,0,1,-1};
int result;

bool isFinshed()
{
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (c[i][j] == '*') return false;
	return true;
}

void dfs(int x, int y)
{
	for (int i = 0; i < 5; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
			if (c[nx][ny] == '.') c[nx][ny] = '*';
			else c[nx][ny] = '.';
		}
	}
}

void find(int x, int y, int m, int cnt)
{
	if (m == 1) dfs(x, y);

	if (isFinshed()) {
		result = min(result, cnt);
		dfs(x, y);
		return;
	}

	if (!(x == 2 && y == 2)) {
		if (y == 2) for (int i = 0; i < 2; i++) find(x + 1, 0, i, cnt + i);
		else for (int i = 0; i < 2; i++) find(x, y + 1, i, cnt + i);
	}

	if (m == 1) dfs(x, y);
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		result = 9999;
		for (int i = 0; i < 3; i++) scanf("%s", c[i]);
		for (int i = 0; i < 2; i++) find(0, 0, i, i);
		printf("%d\n", result);
	}
	return 0;
}