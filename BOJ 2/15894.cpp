#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
int main(){
	scanf("%d", &n);
	ll high = 1;
	ll down = n;
	ll side = 2 * n;
	ll side2 = n - 1;
	ll ans = high + down + side + side2;
	printf("%lld\n", ans);
	return 0;
}