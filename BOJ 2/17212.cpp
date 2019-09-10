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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
vector<int> coin;
int dp[100001];
int go(int k) {
	if (k == 0) return 0;
	int &ret = dp[k];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = coin.size() - 1; i >= 0; i--) {
		if (k >= coin[i]) ret = min(ret, go(k - coin[i]) + 1);
	}
	return ret;
}
int main() {
	setbuf(stdout, NULL);
	coin.push_back(1), coin.push_back(2), coin.push_back(5), coin.push_back(7);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%d\n", go(n));
	return 0;
}
