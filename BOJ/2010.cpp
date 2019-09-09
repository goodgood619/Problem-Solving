#include <stdio.h>
int n,Max;
int arr[500001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n-1; i++) {
		scanf("%d", &arr[i]);
		Max += (arr[i] - 1);
	}
	scanf("%d", &arr[n]);
	Max += arr[n];
	printf("%d\n", Max);
	return 0;
}