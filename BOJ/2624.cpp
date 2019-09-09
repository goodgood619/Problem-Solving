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
int t,n;
vector<P> coin;
int dp[105][10005];
int go(int index, int k) {
	if (k == 0) return 1;
	if (k < 0 || index < 0) return 0;
	int &ret = dp[index][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= coin[index].second; i++) {
		if (k - i * coin[index].first>=0) {
			ret += go(index - 1, k - i * coin[index].first);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int money, cnt;
		scanf("%d%d", &money, &cnt);
		coin.push_back({ money,cnt });
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(coin.size() - 1, t));
	return 0;
}