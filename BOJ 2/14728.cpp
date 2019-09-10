#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[105][10005];
int n, t;
typedef pair <int, int> P;
P score[10000];
int go(int n, int t) {
	if (t <= 0) return 0;
	if (n == 0) return 0;
	int &ret = dp[n][t];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(n - 1, t)); // 알고보니 시간이 더 적은 과목이 만족도가 높을수있으니까 n을 계속줄여본다음에, n을 1부터 차츰 증가시키면서 값을 반환해야함
	if(t >= score[n].first) ret = max(ret, go(n - 1, t - score[n].first) + score[n].second);
	return ret;
}
int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &score[i].first, &score[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n, t));
	return 0;
}