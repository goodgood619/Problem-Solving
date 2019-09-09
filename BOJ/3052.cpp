#include <stdio.h>

int main()
{
	// 10개중 42로 나눈 나머지에서 서로 다른 나머지를 갯수를 체크하여 반환
	int arr[10];
	int zero = 0;
	int remainder[42] = { 0 };
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		remainder[arr[i] % 42]++;
	}
	for (int i = 0; i < 42; i++)
	{
		if (remainder[i]>0)
			cnt++;
	}
	
	printf("%d", cnt);
	return 0;
}