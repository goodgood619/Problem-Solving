#include <stdio.h>
#include <algorithm>
using namespace std;
int arr1[101][101];
int arr2[101][101];
int arr3[101][101];
int n, m,k,r;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	scanf("%d%d", &m, &r);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= r; j++) {
			scanf("%d", &arr2[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=r; j++) {
			for (int p = 1; p <= m; p++){
				arr3[i][j]+= arr1[i][p] * arr2[p][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= r; j++) {
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
	return 0;
}