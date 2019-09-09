#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int n;
int house[10005];
int dp[10005][2];
bool visited[10005];
vector<vector<int>> a;
vector<vector<int>> child;
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
	if (child[here].size() == 0 && ok == 0) {
		return 0;
	}
	else if (child[here].size() == 0 && ok == 1) {
		return house[here];
	}
	int &ret = dp[here][ok];
	if (ret != -1) return ret;
	ret = -1e9;
	int notemp = 0, temp = house[here];
	bool check1 = false, check2 = false;
	if (ok == 0) { //현재마을을 우수마을로 선택하지X
		check1 = true;
		for (int i = 0; i < child[here].size(); i++) {
			notemp += max(go(child[here][i], 0), go(child[here][i], 1));
		}
	}
	else { //현재마을을 우수마을로 선택
		check2 = true;
		for (int i = 0; i < child[here].size(); i++) {
			temp += go(child[here][i], 0);
		}
	}
	if (check1 && check2) ret = max(ret,max(notemp, temp));
	if (!check1 && check2) ret = max(ret, temp);
	if (check1 && !check2) ret = max(ret, notemp);
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &house[i]);
	}
	a.resize(n + 1);
	child.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		a[left].push_back(right);
		a[right].push_back(left);
	}
	dfs(1);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", max(go(1, 0), go(1, 1)));
	return 0;
}