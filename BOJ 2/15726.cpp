#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a, b, c;
int main(){
	scanf("%lld%lld%lld", &a, &b, &c);
	ll ans = max((double)a*b / c, (double)a / b*c);
	printf("%lld\n", ans);
	return 0;
}