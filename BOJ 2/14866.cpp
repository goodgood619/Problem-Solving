#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> a;
vector<vector<int>> subspanningtree;
int strong[300005];
int weak[300005];
int parent[300005];
int discover[300005];
typedef long long ll;
void dfs(int here, int high) {
	for (int i = 0; i < a[here].size(); i++) {
		int down = a[here][i];
		if (down != high) { // down이랑 high가 같으면 안되니까, 같아버리면 왔다가 다시 돌아가는구조
			if (discover[down] == 0) {
				discover[down] = discover[here] + 1;
				subspanningtree[here].push_back(down); // 사실상 dfs subspanning tree를 구성하는 용도
				int precnt = strong[here];
				// dfs 탐색이전에 아래에서 나한테 오는지 안오는지는 전혀 모르지(다녀오면서 부하놈들이 있습니다)
				// 라고 알려줘야 알수있는것
				// 하지만 딱하나 알수있는건, precnt는 here로 오는 down내에 있는 Backedge의 갯수
				dfs(down, here);
				parent[down] = strong[here] - precnt;
				strong[here] += strong[down];
				weak[here] += weak[down];
			}
			else if (discover[here] > discover[down]) {
				strong[down]++;
				weak[here]++;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	subspanningtree.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	discover[1] = 1;
	dfs(1, 0);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		bool check = false;
		int ok = 0;
		for (int j = 0; j < subspanningtree[i].size(); j++) {
			ok = subspanningtree[i][j];
			if (strong[ok] || weak[ok] - parent[ok] >= 2) {
				check = true;
				break;
			}
		}
		if (check || m - (n - 1) - weak[i] != 0) continue;
		else {
			ans += i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}