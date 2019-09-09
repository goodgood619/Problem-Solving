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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n, k;
int gak[15];
int dp[365];
int go(int k) {
	if (k > 360) return 0;
  	int &ret = dp[k];
	if (ret != -1) return ret;
	ret = 1;


	for (int i = 1; i <= n; i++) {
		ret=go((k + gak[i])%360);
		if ((k - gak[i])%360 >= 0) {
			ret=go((k - gak[i])%360);
		}
		else {
			ret=go(abs((k - gak[i])%360));
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &gak[i]);
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= k; i++) {
		int num;
		scanf("%d", &num);
		go(0);
		dp[num%360] == 1 ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}