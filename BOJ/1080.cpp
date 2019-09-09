#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m,idx,idy,cnt,cnt2;
char c[55][55];
char ar[55][55];
bool visited[55][55];
void dfs(int x, int y) {
	for (int i = x; i <= x + 2; i++) {
		for (int j = y; j <= y + 2; j++) {
			if (c[i][j] == '0') c[i][j] = '1';
			else c[i][j] = '0';
		}
	}
	for (int i = x; i <= x + 2; i++) {
		for (int j = y; j <= y + 2; j++) {
			if (c[i][j] == ar[i][j])
				visited[i][j] = true;
			else
				visited[i][j] = false;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &c[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &ar[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == ar[i][j])
				visited[i][j] = true;
			else
				visited[i][j] = false;
		}
	}


	if (n < 3 || m < 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (c[i][j] == ar[i][j])
				{
					visited[i][j] = true;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				if (visited[i][j])
					cnt++;
			}
		}
		if (cnt == n*m)
			printf("%d\n", 0);
		else
		printf("%d\n", -1);
	}
	else {
		for (int i = 0; i < n-2; i++)
		{
			for (int j = 0; j < m-2; j++)
			{
				if (!visited[i][j])
				{
					dfs(i, j);
					cnt++;
				}
				else continue;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j])
					cnt2++;
			}
		}
		if (cnt2 == n*m)
			printf("%d\n", cnt);
		else
			printf("%d\n", -1);
	}
	return 0;
}