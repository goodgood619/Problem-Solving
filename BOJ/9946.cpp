#include <stdio.h>
#include <string.h>
int main()
{
	char c1[1001];
	char c2[1002];
	int arr[1002] = { 0 };
	int cnt = 0;
	int j = 0;
	int index = 0;
	while (1)
	{
		scanf("%s",c1);
		scanf("%s", c2);
		if (!(strcmp(c1,"END")) && !(strcmp(c2,"END"))) //END 만나면
			break;
		for (int i = 0; i < strlen(c1);i++)
		{
			if (c1[i] == c2[j] && arr[i]!=1)
			{
				arr[i] = 1;
				i = 0;
				j++;
				cnt++;
				if (i == 0)
					i--;
			}
			
		}
		if (cnt == strlen(c1))
			printf("Case %d: same\n", index+1);
		else
			printf("Case %d: different\n", index+1);
		index++;
		j = 0;
		cnt = 0;
		for (int i = 0; i < strlen(c1); i++)
			arr[i] = 0;
	}
	return 0;
}