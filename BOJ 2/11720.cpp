#include <stdio.h>
int main()
{
	int n;
	int sum = 0;
	scanf("%d", &n);
	char c[101] = {NULL,};
		scanf("%s", c);
		for (int i = 0; i < n; i++)
		sum += (c[i] - '0');

		printf("%d", sum);
	return 0;
}