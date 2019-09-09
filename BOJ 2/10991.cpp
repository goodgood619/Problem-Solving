#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	int r = 1;
	for (int i = n; i>=1; i--) {
		for (int j = i - 1; j >0; j--)
			printf(" ");
		for (int k = 1; k <= 2 * r - 1; k++) {
			if (k % 2 == 0)
				printf(" ");
			else
				printf("*");
		}
		r++;
		printf("\n");
	}
	return 0;
}