#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
ll dp[210][105][10];
ll cow[210];
int n, k;
ll ans = 99999999999;
#define INF 99999999999
ll go(int start,int cnt,int k){
	if (k == 0){
		if (cnt>0) return INF;
		else return 0;
	}
	ll &ret = dp[start][cnt][k];
	if (ret != -1) return ret;
	ret = INF;
	ll value = 0;
	for (int i = 0,j=cnt;j>=0;i++,j--) {
		value += cow[start+i]*i;
		ret = min(ret,value+go(start+i+1,j-1,k-1));
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &cow[i]);
	}
	for (int i = 1; i <= n; i++) {
		cow[i + n] = cow[i];
	}
	memset(dp, -1, sizeof(dp));
	// 시작위치가 어디인지 ㅇㅇ
	for (int i = 1; i <= n; i++){
		ans = min(ans,go(i,n,k));
	}
	printf("%d\n", ans);
	return 0;
}