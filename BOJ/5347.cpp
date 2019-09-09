#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int t;
ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
int main(){
	scanf("%d", &t);
	while (t--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		ll Min = gcd(a, b);
		printf("%lld\n", a / Min*b / Min*Min);
	}
	return 0;
}