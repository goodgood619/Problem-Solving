#include <stdio.h>
int main()
{
	char c[10][10];
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &c[i][j]);
		}
	}

	for (int i =0; i<=n-1; i++)
	{
		for (int j =m-1; j>=0; j--)
		{
			printf("%c", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}