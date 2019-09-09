#include <stdio.h>
int arr[100];
int t,n;
int ok[100000];
int main() {
	scanf("%d", &t);
	for (int i = 1; i <100; i++)
		arr[i] = (i*(i + 1)) / 2;
	for (int i = 1; i <50; i++) {
		for (int j = 1; j <50; j++) {
			for (int k = 1; k <50; k++) {
				n = arr[i] + arr[j] + arr[k];
				ok[n] = 1;
			}
		}
	}
	while (t--)
	{
		int num;
		scanf("%d", &num);

		if (ok[num])
			printf("%d\n", 1);
		else
			printf("%d\n", 0);
	}
	return 0;
}