#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
// dp[n][0] : n+1번째날부터 끝나는날까지 얻은 간식의 총합, 그러나 n번째 날은 간식을 선택하지 않았을때
// dp[n][1] : n+1번째날부터 끝나는날까지 얻은 간식의 총합, 그러나 n번째 날은 간식을 선택하였을때
// 결론 : n=0, 현재간식 =0에서 시작을 해서 구한다
int maxEat(int curDay, int endDay, int taste, int eatCheck, vector<int>& eat, vector<vector<int>>& dp) {
	if (curDay > endDay) return 0;
	int& ret = dp[curDay][eatCheck];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = curDay + 1; i <= endDay; i++) {
		int nextTaste = eat[i];
		// 다음 간식을 선택할지 말지
		if (taste < nextTaste) {
			ret = max(ret, maxEat(i, endDay, nextTaste, 1, eat, dp) + nextTaste);
			ret = max(ret, maxEat(i, endDay, taste, 0, eat, dp));
		}
		// 다음 간식을 먹을수 없을때
		else ret = max(ret, maxEat(i, endDay, taste, 0, eat, dp));
	}
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> eat;
	eat.assign(n + 1, 0);
	vector<vector<int>> dp;
	dp.assign(n + 1, vector<int>(2, -1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &eat[i]);
	}
	maxEat(0, n, 0, 0, eat, dp);
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 1; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans);
	dp.clear();
	for (int i = 0; i <= n; i++) dp[i].clear();
	eat.clear();
	return 0;
}