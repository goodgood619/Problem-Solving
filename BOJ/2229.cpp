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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int arr[1005];
int dp[1005];
int n;
int go(int index) {
	if (index > n) return 0;
	int &ret = dp[index];
	if (ret != -1) return ret;
	int high = 0, low = 1e9;
	for (int i = index,j=1; i <= n; i++,j++) {
		high = max(high, arr[i]);
		low = min(low, arr[i]);
		ret = max(ret, go(index+j) + high - low);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1));
	return 0;
}