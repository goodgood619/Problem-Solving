#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int arr[10001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	if (prev_permutation(&arr[1], &arr[n + 1])) {
		for (int i = 1; i <= n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
		printf("%d\n", -1);
	return 0;
}