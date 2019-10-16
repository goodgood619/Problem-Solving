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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int t,n;
int dp[105][10005];
int coin[105];
int Case = 1;
void go(int index,int sum) {
	if (index >=n) {
		dp[index][sum] = 1;
		return;
	}
	int &ret = dp[index][sum];
	if (ret != -1) return;
	ret = 1;
	go(index + 1,sum + coin[index]);
	go(index + 1, sum);
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		memset(coin, 0, sizeof(coin));
		for (int i = 0; i <n; i++) {
			scanf("%d", &coin[i]);
		}
		go(0,0);
		int ans = 0;
		for (int i = 0; i <= 10000; i++) {
			for (int j = 0; j <= 100; j++) {
				if (dp[j][i] == 1) {
					ans++;
					break;
				}
			}
		}
		printf("#%d %d\n", Case++, ans);
	}
	return 0;
}