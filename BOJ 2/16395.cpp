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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int n,k;
int arr[15];
int Max = -2000000000;
int Min = INT_MAX;
bool ok;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll dp[35][35];
ll go(int n, int k){
	if (n == k) return 1;
	if (n < 0) return 0;
	if (n <= 0) return 1;
	if (k == 0) return 1;
	ll &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	ret = go(n - 1, k - 1) + go(n - 1, k);
	return ret;
}
int main(){
	scanf("%d%d", &n, &k);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(n - 1, k - 1));
	return 0;
}