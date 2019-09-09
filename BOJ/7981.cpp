#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
vector<vector<ll>> a;
int n;
ll weakpush[200005];
ll strongpush[200005];
ll dp[200005];
bool visited[200005];
#define INF 10000000000000
int dfs(int here){
	if (visited[here]) return INF;
	ll &ret = dp[here];
	if (ret != -1) return ret;
	ret = strongpush[here];
	ll sum = weakpush[here];
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		sum+=dfs(next);
	}
	ret = min(ret, sum);
	visited[here] = false;
	return ret;
}
int main(){
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		ll weak, strong, cnt;
		scanf("%lld%lld%lld", &weak, &strong, &cnt);
		weakpush[i] = weak;
		strongpush[i] = strong;
		for (int j = 1; j <= cnt; j++){
			ll num;
			scanf("%lld", &num);
			a[i].push_back(num);
		}
	}
	memset(dp, -1, sizeof(dp));
	ll ans = dfs(1);
	printf("%lld\n", ans);
	return 0;
}