#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
int main(){
	while (1) {
		ll n, m;
		scanf("%lld%lld", &n, &m);
		if (n == 0 && m == 0) break;
		if (m == 0 || m == n) {
			printf("1\n");
			continue;
		}
		if (m > n - m) {
			m = n - m;
		}
		ll ans = 1;
		ll mod = 1;
		ll p = m;
		for (ll i = 1; i <= p; i++){
			ans = ans*(n -m+i)/i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}