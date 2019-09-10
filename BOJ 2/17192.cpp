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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,k;
int dp[401][401];
int arr[401],Max[401][401];
int go(int n,int k) {
	if (k <0) return 1e9;
	if (k == 0) return n * Max[1][n];
	if (n == 0) return 0;
	int &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < n; i++) {
		ret = min(ret, go(i, k - 1) + (n - i)*Max[i + 1][n]);
	}
	return ret;
}
int main() {
	setbuf(stdout, NULL);
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &k);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int temp = arr[i];
		for (int j = i; j <= n; j++) {
			int temp2 = arr[j];
			Max[i][j] = max(Max[i][j], max(Max[i][j-1], temp2));
		}
	}
	printf("%d\n", go(n, k) - sum);
	return 0;
}