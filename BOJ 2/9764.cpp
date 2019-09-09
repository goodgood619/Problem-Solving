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
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t;
int dp[2005][2005];
vector<int> coin;
int go(int k, int index) {
	if (index >= coin.size()) return 0;
	if (k < 0) return 0;
	if (k == 0) return 1;
	if (coin[index] == k) return 1;
	int &ret = dp[k][index];
	if (ret != -1) return ret;
	ret = 0;
	ret = go(k - coin[index], index + 1) + go(k, index + 1);
	return ret%100999;
}
int main() {
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	while (t--) {
		int n;
		scanf("%d", &n);
		coin.clear();
		for (int i = 1; i <= n; i++) {
			coin.push_back(i);
		}
		printf("%d\n", go(n, 0));
	}
	return 0;
}