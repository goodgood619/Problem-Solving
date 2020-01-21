#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
int main(){
	Int t;
	scanf("%d", &t);
	while (t--) {
		Int p, q, a, b, c, d;
		scanf("%d%d%d%d%d%d", &p, &q, &a, &b, &c, &d);
			Int coin = 0,ans=0;
			for (int i = q, j = 0; i >= 0; i -= c, j++) {
				coin = max(coin, d * j);
			}
			
			double t = (double)abs(p - coin) / (a + b);
			int temp = (int)t;
			ans = max(ans, min(p+a*temp,coin-b*temp));
			ans = max(ans, min(p + a * (temp + 1), coin - b * (temp + 1)));
			ans = max(ans, min(p + a * (temp - 1), coin - b * (temp - 1)));
			ans = max(ans, min(p - a * temp, coin + b * temp));
			ans = max(ans, min(p - a * (temp + 1), coin + b * (temp + 1)));
			ans = max(ans, min(p - a * (temp - 1), coin + b * (temp - 1)));
			printf("%d\n", ans);
	}
	return 0;
}