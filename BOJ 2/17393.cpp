#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <vector>
typedef int32_t Int;
typedef int64_t ll;
using namespace std;
int main() {
	Int n;
	scanf("%d", &n);
	vector<ll> a, b;
	for (int i = 0; i < n; i++) {
		ll num;
		scanf("%lld", &num);
		a.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		ll num;
		scanf("%lld", &num);
		b.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		ll ans = upper_bound(b.begin() + i+1, b.end(), a[i]) - (b.begin()+ i+ 1);
		printf("%lld ", ans);
	}
	a.clear(),b.clear();
	return 0;
}