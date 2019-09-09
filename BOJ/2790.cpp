#include <stdio.h>
#include <algorithm>
using namespace std;
int n,cnt,Max;
int arr[300003];
int temp[300003];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		temp[i] = arr[i];
	}
	sort(arr+1, arr + n+1);
	sort(temp+1, temp + n+1);
	int k = n;

	for (int i = 1; i <= n; i++) {
		arr[i] += (k);
		k--;
		Max=max(arr[i], Max);
	}
	for (int i = 1; i <= n; i++) {
		if (Max<=temp[i] + n)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}