#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <vector>
typedef int32_t Int;
typedef int64_t ll;
using namespace std;
int main() {
	Int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		n *= 2;
		ll left = 1, right = 1e9,ans = 0;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll temp = (mid + 1) * mid;
			if (temp > n) right = mid - 1;
			else {
				ans = max(ans,mid);
				left = mid + 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}