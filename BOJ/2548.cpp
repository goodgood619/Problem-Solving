#include <stdio.h>
#include <algorithm>
using namespace std;
int n, Max;
int arr[20001];
int ans = 999999999;
int ans2;
int idx;
int mid;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
		mid += arr[i];
	mid /= n;

	mid += 10;
	for (; mid >= 1;) {
		for (int j = 1; j <= n; j++) {
			if (mid - arr[j] < 0)
				ans2 += (arr[j] - mid);
			else
				ans2 += (mid- arr[j]);
		}
		if (ans >= ans2) {
			ans = ans2;
			idx = mid;
		}
		ans2 = 0;
		mid--;
	}
	printf("%d\n", idx);
	return 0;
}