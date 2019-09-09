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
int n, t;
int dp[1001];
int go(int index) {
	if (index <= 1) return 1;
	int &ret = dp[index];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(index - 1) + go(index - 2);
	ret %= 10007;
	return ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n) % 10007);
	return 0;
}