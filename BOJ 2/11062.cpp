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
int n;
int dp[2][1005][1005];
int arr[1005];
int go(int here, int left, int right) {
	if (left == right) {
		if (here) return arr[left];
		else return 0;
	}
	int &ret = dp[here][left][right];
	if (ret != -1) return ret;
	ret = 0;
	if (here == 1) { //근우
		ret = max(go(0, left + 1, right) + arr[left],go(0, left, right - 1) + arr[right]);
	}
	else { //명우
		ret = min(go(1, left + 1, right), go(1, left, right - 1)); //여기가 이해가 안되네
	}
	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf(" %d", &arr[i]);
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n",go(1, 1, n));
	}
	return 0;

}