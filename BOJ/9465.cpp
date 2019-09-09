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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, t;
int dp[3][100005];
int arr[3][100005];
int go(int here, int index) {
	if (index > n) return 0; //끝까지 간경우
	int &ret = dp[here][index];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, max(max(go((here + 1) % 2, index+1), go(here, index + 1)), go((here + 1) % 2, index + 1) + arr[here][index]));
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int j = 0; j <= 1; j++) {
			for (int i = 1; i <= n; i++) {
				scanf(" %d", &arr[j][i]);
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", max(go(1, 1),go(1,0)));
	}
	return 0;
}