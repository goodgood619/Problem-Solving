#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	int q = n - 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i;j++)
			printf(" ");
		for (int k = 1; k <= 2 * q + 1;k++)
			printf("*");
		q--;
		printf("\n");
	}
	int r = 1;
	for (int j = n-1; j>0; j--) {

		for (int k = j - 1; k > 0;k--)
			printf(" ");
		for (int p = 1; p <= 2 * r + 1;p++)
			printf("*");
		printf("\n");
		r++;
	}
	return 0;
}