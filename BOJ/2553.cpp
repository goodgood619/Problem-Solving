#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
int main(){
	scanf("%d", &n);
	ll start = 1;
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		start *= i;
			while (start % 10 == 0) {
				start /= 10;
			}
			start= start % 100000;
			ans = start % 10;
	}
	printf("%lld\n", ans);
	return 0;
}