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
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
string s;
int dp[45];
int go(int here) {
	if (here >= s.size()) return 1;
	int &ret = dp[here];
	if (ret != -1) return ret;
	ret = 0;
	int sum = 0;
	if (s[here] - '0' != 0) ret += go(here + 1);
	if (here + 1 < s.size()) {
		sum += (s[here] - '0') * 10;
		sum += (s[here + 1] - '0');
		if (sum >= 10 && sum <= 34 ) {
			ret += go(here + 2);
		}
	}
	return ret;
}
int main() {
	cin >> s;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0));
	return 0;
}