#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char c[50];
int arr[50];
int n, k,p,idx;
int main() {
	scanf("%d%d", &n, &k);
	scanf("%d", &arr[0]);
	for (int i = 1; i < n; i++)
		scanf(",%d", &arr[i]);

	for (int i = 1; i <= k; i++) {
		int p = n;
		for (int j = 0; j <=p - i; j++){
			if (j == p - i) {
				arr[j] = 0; 
				idx = j;
				break;
			}
			arr[j]=arr[j + 1] - arr[j];
		}
	}
	if (k >= 1) {
		for (int i = 0; i < idx; i++) {
			if (i == idx - 1)printf("%d\n", arr[i]);
			else {
				printf("%d", arr[i]);
				printf(",");
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i == n - 1) printf("%d\n", arr[i]);
			else {
				printf("%d", arr[i]);
				printf(",");
			}
		}
	}
	return 0;
}