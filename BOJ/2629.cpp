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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,m;
int dp[35][50005];
vector<int> coin;
void go(int idx, int k) {
	if (idx >= n) {
		dp[idx][k] = 1;
		return;
	}
	int &ret = dp[idx][k];
	if (ret != -1) return;
	ret = 1;
	go(idx + 1, k);
	go(idx + 1, k + coin[idx]);
	go(idx + 1, abs(k - coin[idx]));
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		coin.push_back(num);
	}
	scanf("%d", &m);
	memset(dp, -1, sizeof(dp));
	go(0, 0);
	// 1g과 4g으로 만들수 있는 경우의수는 -> 1g, 4g(그자체의 경우)+ 1g-4g(-3g이아니라 3g) 1g+4g(5g) (빼거나 더하거나!!!)
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		dp[n][k] == 1 ? printf("Y ") : printf("N ");
	}
	
	return 0;
}