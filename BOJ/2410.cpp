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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll dp[1000005];
vector<ll> coin;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i *= 2) {
		coin.push_back(i);
	}
	dp[0] = 1;
	for (int j = 0; j <coin.size(); j++) {
		for (int i = 1; i<=n; i++) {
			if(i>=coin[j]) dp[i] += dp[i - coin[j]];
			dp[i] %= mod;
		}
	}
	printf("%lld\n", dp[n]%mod);
	return 0;
}