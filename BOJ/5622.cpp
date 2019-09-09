#include <stdio.h>
#include <string.h>
int main()
{

	char c[20];
	scanf("%s", c);
	int sum = 0;
	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i] >= 'A' && c[i] <= 'C')
			sum += 3;
		if (c[i] >= 'D'&& c[i] <= 'F')
			sum += 4;
		if (c[i] >= 'G' && c[i] <= 'I')
			sum += 5;
		if (c[i] >= 'J' && c[i] <= 'L')
			sum += 6;
		if (c[i] >= 'M' && c[i] <= 'O')
			sum += 7;
		if (c[i] >= 'P' && c[i] <= 'S')
			sum += 8;
		if (c[i] >= 'T'&& c[i] <= 'V')
			sum += 9;
		if (c[i] >= 'W' && c[i] <= 'Z')
			sum += 10;
	}
	printf("%d", sum);

	return 0;
}