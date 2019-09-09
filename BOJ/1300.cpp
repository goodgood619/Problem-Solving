#include <cstdio>
#include <algorithm>
using namespace std;
long long n, k;
int main(){
	scanf("%lld%lld", &n, &k);
	long long left = 1;
	long long right = n*n;
	while (left <= right) {
		long long cnt = 0;
		long long mid = (left + right) / 2;
		for (long long i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt < k) left = mid + 1;
		else right = mid - 1;
	}
	printf("%lld\n", left);
	return 0;
}
