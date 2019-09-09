#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int a, b;
typedef long long ll;
int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
int main(){
	scanf("%d%d", &a, &b);
	ll xy = b / a;
	ll x = 1;
	ll y = 1000000000;
	ll ans = 9999999999999;
	ll ans1= 0;
	ll ans2=0;
	for (ll i = 1; i <= sqrt(xy); i++){
		if (xy%i == 0){
			x = max(x, a*i);
			y = min(y, a*(xy / i));
			bool check = false;
			int what = gcd(x, y);
			if (ans > x + y && what==a) {
				ans = x + y;
				ans1 = x;
				ans2 = y;
			}
		}
		else continue;
	}
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}