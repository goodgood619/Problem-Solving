#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a, b;
int main(){
	scanf("%lld%lld", &a, &b);
	if (a > b) {
		ll temp = a;
		a = b;
		b = temp;
	}
	if (a == b || a+1==b) printf("0");
	else {
		printf("%lld\n", b - a - 1);
		for (ll i = a + 1; i < b; i++) {
			printf("%lld ", i);
		}
	}
	return 0;
}
