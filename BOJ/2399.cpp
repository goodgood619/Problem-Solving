#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[10000];
int n;
long long sum;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else {
				sum += abs(arr[i] - arr[j]);
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}