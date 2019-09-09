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
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
int n, m;
int dp[105][105];
int arr[105];
int sum[105][105];
int go(int start, int cnt) {
	if (cnt == m) return 0;
	if (start>n) {
		if (cnt == m) return 0;
		else return -1e9;
	}
	int &ret = dp[start][cnt];
	if (ret != -1) return ret;
	ret = -1e9;
	ret = max(ret,go(start+1,cnt));
	for (int i = start; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			int p = sum[start][i];
			ret = max(ret, go(i + j, cnt + 1) + p);
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = i; j <= n; j++) {
			temp += arr[j];
			sum[i][j] = temp;
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, 0));
	return 0;
}