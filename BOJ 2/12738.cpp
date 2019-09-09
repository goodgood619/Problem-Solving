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
int dp[1000001],arr[1000001];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	int en = 0;
	dp[0] = -2e9;
	for (int i = 1; i <= n; i++) {
		int *idx = lower_bound(dp + 1, dp + en + 1,arr[i]);
		*idx = arr[i];
		if (idx == dp + en + 1) en++;
	}
	printf("%d\n", en);
	return 0;
}