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
typedef pair<pair<int, int>,string> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int rx[8] = { 0,0,1,-1,1,1,-1,-1 };
int ry[8] = { 1,-1,0,0,1,-1,1,-1 };
int n;
int dp[5005][5005];
string s;
int go(int left, int right) {
	if (left >= right) return 0;
	int &ret = dp[left][right];
	if (ret != -1) return ret;
	ret = 1e9;
	if (s[left] == s[right]) {
		ret = min(ret, go(left + 1, right - 1));
	}
	else {
		ret = min(ret, min(go(left + 1, right) + 1, go(left, right - 1) + 1));
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	cin >> s;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, s.size() - 1));
	return 0;
}