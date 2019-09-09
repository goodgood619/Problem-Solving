#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
typedef long long ll;
int t;
int main(){
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		ll temp = n*n;
		ll sum = 0;
		int cnt = 0;
		bool ok = false;
		while (temp > 0){
			sum += (temp % 10) * pow(10, cnt);
			if (sum == n) {
				ok = true;
				break;
			}
			temp /= 10;
			cnt++;
		}
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}