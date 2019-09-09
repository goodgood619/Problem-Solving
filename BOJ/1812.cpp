#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1001];
int n,sum;
int k;
int temp;
int main() {
	scanf("%d", &n);
	for (int i = 0; i <n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sum /= 2;
	int p = sum;
	for (int i = 0; i <n; i++) {
		k = temp;
		sum = p;
		for (int j = 0; j < n / 2; j++){
			sum -= arr[(k+ 1) % n];
			k += 2;
		}
		temp++;
		printf("%d\n", sum);
	}
	return 0;
}