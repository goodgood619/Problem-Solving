#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	char c[100];
	scanf("%d", &n);
	int sum = 0;
	int score=0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", c);

		for (int j = 0; j < strlen(c); j++)
		{
			if (c[j] == 'X')
				score= 0;
			else
			{
				++score;
				sum += score;
			}
		}
		printf("%d\n", sum);
		sum = 0;
		score= 0;
	}



	return 0;
}