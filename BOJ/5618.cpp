#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int n,k;
int arr[3];
int ok[100000];
int go(int a, int b) {
	if (a%b == 0) return b;
	return go(b, a%b);
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]);}
	if (n == 2) {
		sort(arr, arr + 3);
		int Max = go(arr[1], arr[2]);
		for (int i = 1; i <= sqrt(Max); i++) {
			if (Max%i == 0) {
				if ((Max / i) == i) {
					ok[k++] = Max / i;
					continue;
				}
				ok[k++] = Max / i;
				ok[k++] = i;
			}
		}
		sort(ok, ok + k);
		for (int i = 0; i < k; i++) {
			printf("%d\n", ok[i]);
		}
	}
	else if (n == 3) {
		sort(arr, arr + 3);
		int Max = go(arr[0], arr[1]);
		for (int i = 1; i <= sqrt(Max); i++) {
			if (Max%i == 0) {
				if ((Max / i) == i) {
					ok[k++] = Max / i;
					continue;
				}
				ok[k++] = Max / i;
				ok[k++] = i;
			}
		}
		sort(ok, ok + k);
		for (int i = 0; i < k; i++) {
			if (arr[2] % ok[i] == 0) printf("%d\n", ok[i]);
			else continue;
		}
	}
	return 0;
}