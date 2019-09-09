#include <cstdio>
#include <algorithm>
using namespace std;
int n, en, k;
int dp[10005];
int path[10005];
bool visited[10005];
int ans[10005];
typedef pair <int, int> P;
P line[100005];
P newline[10005];
void go(int idx, int en) {
	if (idx == 0) return;
	if (path[idx] == en) {
		go(idx - 1, en - 1);
		visited[idx] = true;
	}
	else {
		go(idx - 1, en);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &line[i].first); }
	for (int i = 1; i <= n; i++) { scanf("%d", &line[i].second); }

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			if (line[i].first == line[j].second) {
				newline[i].first = line[i].first;
				newline[i].second = j;
				break;
			}
		}
	}
	dp[0] = -98765432;
	for (int i = 1; i <= n; i++) {
		int *idx = lower_bound(dp + 1, dp + en + 1, newline[i].second);
		*idx = newline[i].second;
		path[i] = distance(dp, idx);
		if (idx == dp + en + 1) { en++; }
	}

	printf("%d\n",en);
	go(n, en);
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			ans[k++] = newline[i].first;
		}
	}
	sort(ans, ans + k);
	for (int i = 0; i < k; i++) { printf("%d ", ans[i]); }
	return 0;
}