#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
vector<vector<P>> a;
vector<ll> ans;
int n, start;
ll total,real;
bool visited[100005];
void dfs(int here, ll sum){
	bool check = false;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int nextcost = a[here][i].first;
		int next = a[here][i].second;
		if (!visited[next]) {
			total += nextcost;
			check = true;
			dfs(next, sum + nextcost);
		}
	}
	if (!check)ans.push_back(sum);
}
int main() {
	scanf("%d%d", &n, &start);
	a.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ cost,second });
		a[second].push_back({ cost,first });
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start, 0);
	sort(ans.begin(), ans.end());
	ll diff = ans[ans.size() - 1];
	real=(total - diff) * 2 + diff;
	printf("%lld\n", real);
	return 0;
}