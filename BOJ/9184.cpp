#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[200][200][200];
ll go(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	ll &ret = dp[a][b][c];
	if (ret != -1) return ret;
	if (a > 20 || b > 20 || c > 20) ret=go(20, 20, 20);
	else if (a < b && b < c) ret=go(a, b, c - 1) + go(a, b - 1, c - 1) - go(a, b - 1, c);
	else {
			ret=go(a - 1, b, c) + go(a - 1, b - 1, c) + go(a - 1, b, c - 1) - go(a - 1, b - 1, c - 1);
	}
	return ret;
}
int main(){
	memset(dp, -1, sizeof(dp));
	while (1){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;
		ll ans=go(a, b, c);
		printf("w(%d, %d, %d) = %lld\n",a,b,c,ans);
	}
	return 0;
}