#include <cstdio>
#include <algorithm>
#include <cstdint>
using namespace std;
typedef int64_t ll;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int* arr = new int[n];
	int* diff = new int[n-1];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n - 1; i++) diff[i] = arr[i + 1] - arr[i];
	sort(diff, diff + n - 1);
	ll sum = 0;
	for (int i = 0; i < (n - 1) - (k - 1); i++) {
		sum += diff[i];
	}
	printf("%lld\n", sum);
	delete[] arr, diff;
	return 0;
}