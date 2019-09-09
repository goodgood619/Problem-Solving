#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
ll board[105][105];
int n, m;
ll ans;
ll sum[105][105];
int t;
int main(){
	scanf("%d",&t);
	while (t--){
		ll st, en;
		scanf("%lld%lld", &st, &en);
		ll dist = en - st;
		//n^2-n+1 ~ n^2 : n*2-1
		// n^2+1 ~ n^2+n : n*2
		ll n = 1;
		ll ans = 0;
		while (1) {
			ll p = n*n;
			if (dist >= n*n - n + 1 && dist <= n*n) {
				ans = n * 2 - 1;
				break;
			}
			else if (dist >= n*n + 1 && dist <= n*n + n) {
				ans = n * 2;
				break;
			}
			n++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}