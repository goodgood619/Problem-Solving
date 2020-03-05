#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int sum[50001] = {}, ans = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		sum[i] += sum[i - 1] + num;
	}
	
	for (int i = 1; i <= n; i++) {
		int left = i, right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			int a = sum[mid] - sum[i - 1];
			int b = sum[n] - a;
			if (a < b) left = mid + 1;
			else right = mid - 1;
			ans = max(ans, min(a, b));
		}
	}
	printf("%d\n", ans);

	return 0;
}