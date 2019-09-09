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
typedef pair < int,int > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,m;
vector<P> coin;
int dp[105][10005];
int go(int index,int k) {
	if (k < 0 || index<0) return 0;
	int &ret = dp[index][k];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(index - 1, k)); // 선택을 안하는경우
	if (k - coin[index].second >= 0) ret = max(ret, go(index - 1, k - coin[index].second) + coin[index].first);//가방에 넣을수있는경우
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	coin.resize(105);
	for (int i = 0; i < n; i++) {
		int money;
		scanf("%d", &money);
		coin[i].first=money;
	}
	int total = 0;
	for (int i = 0; i < n; i++) {
		int money;
		scanf("%d", &money);
		coin[i].second = money;
		total += money;
	}
	memset(dp, -1, sizeof(dp));
	int ans = 1e9;
	for (int i = total; i >= 0; i--) go(coin.size() - 1, i);
	for (int i = 0; i <100; i++) {
		for (int j = total; j >= 0; j--) {
			if (dp[i][j] == -1) continue;
			if (dp[i][j] >= m) {
				ans=min(j, ans);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}