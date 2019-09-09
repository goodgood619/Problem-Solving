#include <cstdio>
#include <algorithm>
using namespace std;
int n,en;
int dp[100001];
typedef pair <int, int> P;
P line[100005];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int port;
		scanf("%d", &port);
		line[i].first = i;
		line[i].second = port;
	}
	sort(line + 1, line + n + 1);
	for (int i = 1; i <= n; i++) {
		int *idx=lower_bound(dp + 1, dp + en + 1, line[i].second);
		*idx = line[i].second;
		if (idx == dp + en + 1) {en++;}
	}
	printf("%d\n", n - en);
	return 0;
}