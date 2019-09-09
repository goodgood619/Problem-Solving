#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
vector<vector<int>> a;
vector<vector<int>> child;
bool visited[1000005];
int dp[1000005][3];
#define INF 1000000000
void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			child[here].push_back(next);
			dfs(next);
		}
	}
}
int go(int here, int ok) {
	if (child[here].size() == 0 && ok == 1) return 1;
	else if (child[here].size() == 0 && ok == 0) return 0;
	int &ret = dp[here][ok];
	if (ret != -1) return ret;
	ret = 1e9;
	bool check1 = false;
	bool check2 = false;
	int nocnt = 0;
	int cnt1 = 1;
	if (ok == 0) { // 현재가 얼리어답터가 아님
		check2 = true;
		nocnt = 0;
		for (int i = 0; i < child[here].size(); i++) {
			int next = child[here][i];
			nocnt += go(next, 1);
		}
	}
	else { //현재가 얼리어답터임
		check1 = true;
		for (int i = 0; i < child[here].size(); i++) {
			int next = child[here][i];
			cnt1 += min(go(next, 0),go(next,1)); // 다음애가 얼리어답터인경우, 다음애가 얼리어답터가 아닌경우
		}
	}
	if(check2&& check1) ret = min(ret, min(nocnt, cnt1));
	if (!check2 && check1) ret = min(ret, cnt1); // 현재가 얼리어답터인쪽만 방문이 되었다면, 현재와 얼리어답터인 애들갯수랑만 비교
	if (check2 && !check1) ret = min(ret, nocnt); // 현재가 얼리어답터가 아닌쪽만 방문이 되었다면, 현재와 얼리어답터가 아닌쪽애들랑만 비교
	return ret;
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	child.resize(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	dfs(1);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", min(go(1,0), go(1,1)));
	return 0;
}