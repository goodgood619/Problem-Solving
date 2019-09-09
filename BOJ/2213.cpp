#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int dp[10005][2];
vector<vector<int>> a;
vector<vector<int>> child;
int weight[10005];
bool visited[10005];
vector<int> temp;
void dfs(int here) {
	if (visited[here]) return;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			child[here].push_back(next);
			dfs(next);
		}
	}
}
int go(int here, bool check) {
	int &ret = dp[here][check];
	if (ret != -1) return ret;
	ret = 0;
	// 현재 정점 선택 ㄴㄴ하면 다음정점에서 최대를 가지는 경우를 택하면됨 ㅇㅇ
	if (!check){
		for (int i = 0; i < child[here].size(); i++) {
			int next = child[here][i];
			ret+=max(go(next, true), go(next, false));
		}
	}
	//본인을 선택하면 그냥 다음에서 오는 값을 누적하면됨
	else{
		ret = weight[here];
		for (int i = 0; i < child[here].size(); i++) {
			int next = child[here][i];
			ret+=go(next, false);
		}
	}
	return ret;
}
void find(int here, bool check) {
	if (check){
		temp.push_back(here);
		for (int i = 0; i < child[here].size(); i++) {
			int next = child[here][i];
			find(next, false);
		}
	}
	else {
		for (int i = 0; i < child[here].size(); i++) {
			int next = child[here][i];
			if (dp[next][0] > dp[next][1]) find(next, 0);
			else find(next, 1);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	a.resize(n + 1);
	child.resize(n + 1);
	for (int i = 1; i <= n; i++) { scanf("%d", &weight[i]); }
	for (int i = 1; i <= n - 1; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	dfs(1);
	memset(dp, -1, sizeof(dp));
	int ans = go(1, true);
	int ans2 = go(1, false);

	if (ans < ans2) {
		find(1, false);
	}
	else {
		find(1, true);
	}
	printf("%d\n", max(ans, ans2));
	sort(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++) {
		printf("%d ", temp[i]);
	}
	return 0;
}