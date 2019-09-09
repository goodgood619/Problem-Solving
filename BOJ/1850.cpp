#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll a, b;
ll p,q;
ll go(ll a, ll b) {
	if (a%b == 0) return b;
	else return go(b, a%b);
}
int main(){
	scanf("%lld%lld", &p, &q);
	ll pp=max(p, q);
	ll qq = min(p, q);
	ll r=go(pp,qq);
	for (int i = 1; i <= r; i++) {
		printf("1");
	}
	printf("\n");
	return 0;
}