#include <stdio.h>
#include <algorithm>
using namespace std;
char c[50][50];
int n,idx,idy;
int gox[5] = { 0,1,1,1,0 };
int goy[5] = { 0,1,0,-1,1 };
int cnt[50][50];
bool check;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n ; j++) {
			scanf(" %c",&c[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= 4; k++) {
				int nx = i + gox[k];
				int ny = j + goy[k];
				int nx2 = i - gox[k];
				int ny2 = j - goy[k];
				if (nx<1 || nx>n || ny<1 || ny>n || nx2<1 || nx2>n || ny2 < 1 || ny2>n) continue;
				if (c[i][j] == '.') continue;
				if (c[i][j] == c[nx][ny] && c[nx2][ny2] == c[i][j] && c[nx][ny] == c[nx2][ny2])
				{
					cnt[i][j] = 1;
					idx = i;
					idy = j;
					break;
				}
			}
			if (idx == i && idy == j)
				break;
		}
		if (idx == i)
			break;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
		{
			if (cnt[i][j] == 1)
				check = true;
		}
	}

	if (check == true)
		printf("%c\n", c[idx][idy]);
	else
		printf("ongoing\n");
	return 0;
}
