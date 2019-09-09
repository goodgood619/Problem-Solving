#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int n, k,ret;
vector<int> ans;
bool go(int sum, int cnt) {
	if (sum == n) ret++;
	if (ret == k) return true;
	for (int i = 1; i <= 3; i++) {
		if (sum + i <= n) {
			if (go(sum + i, cnt + 1)) {
				ans.push_back(i);
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d%d", &n, &k);
	go(0, 0);
	if (ans.empty()) printf("-1\n");
	else {
		printf("%d", ans[ans.size() - 1]);
		for (int i = ans.size() - 2; i >= 0; i--) {
			printf("+%d", ans[i]);
		}
	}
	return 0;
}
