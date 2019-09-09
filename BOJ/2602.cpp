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
string s[2],word;
ll dp[105][2][22];
ll go(int index,int c,int w) {
	if (w >= word.size()) return 1;
	ll &ret = dp[index][c][w];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = index;i<s[c].size(); i++) {
		if (s[c][i] == word[w]) {
			ret += go(i + 1, (c + 1) % 2, w + 1);
		}
	}
	return ret;
}
int main() {
	cin >> word;
	for (int i = 0; i < 2; i++) {
		cin >> s[i];
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0, 0, 0) + go(0, 1, 0));
	return 0;
}