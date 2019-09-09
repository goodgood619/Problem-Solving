#include <stdio.h>
#include <algorithm>
using namespace std;
int cnt[1001];
int cost[1001];
int judge[1001];
int n, m,ans,idx;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);
	for (int j = 1; j <= m; j++) scanf("%d", &judge[j]);

	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (judge[j] < cost[i]) continue;
			else {
				cnt[i]++;
				break;
			}
		}
	}

	for (int i = 1; i <= 1000; i++){
		if (ans < cnt[i]) {
			ans = max(cnt[i], ans);
			idx = i;
		}
	}
	printf("%d\n", idx);
	return 0;
}