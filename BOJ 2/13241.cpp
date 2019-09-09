#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll go(ll a, ll b) {
	if (a == 0) return b;
	else return go(b%a, a);
}
int main(){
		ll a, b;
		scanf("%lld%lld", &a, &b);
		long long Max=go(a, b);
		printf("%lld\n", a/Max*b/Max*Max);
	return 0;
}