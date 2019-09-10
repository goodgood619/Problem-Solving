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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
char c[1000005];
ll dp[1000000][2];
string s;
ll go(int index, int num, char c) {
	if (index >= s.size()) return 1;
	if (s[index] == 'c') {
		ll &ret = dp[index][0];
		if (ret != -1) return ret;
		ret = 0;
		if (index - 1 >= 0) { //중간이거나 마지막값
			if (s[index - 1] == 'c') { //연속
				for (int i = 0; i < 26; i++) {
					if (c == i + 'a') continue;
					ret += go(index + 1, num, i + 'a');
					ret %= mod;
				}
				ret %= mod;
				return ret;
			}
			else { //no연속
				for (int i = 0; i < 26; i++) {
					ret += go(index + 1, num, i + 'a');
					ret %= mod;
				}
				ret %= mod;
				return ret;
			}
		}
		else { //처음값
			for (int i = 0; i < 26; i++) {
				ret += go(index + 1, num, i + 'a');
				ret %= mod;
			}
			ret %= mod;
			return ret;
		}
	}
	else {
		ll &ret = dp[index][1];
		if (ret != -1) return ret;
		ret = 0;
		if (index - 1 >= 0) {//중간이거나 마지막값
			if (s[index - 1] == 'd') {
				for (int i = 0; i < 10; i++) {
					if (i == num) continue;
					ret += go(index + 1, i, c);
					ret %= mod;
				}
				ret %= mod;
				return ret;
			}
			else {
				for (int i = 0; i < 10; i++) {
					ret += go(index + 1, i, c);
					ret %= mod;
				}
				ret %= mod;
				return ret;
			}
		}
		else { // 처음값
			for (int i = 0; i < 10; i++) {
				ret += go(index + 1, i, c);
				ret %= mod;
			}
			ret %= mod;
			return ret;
		}
	}
}
int main(void) {
	scanf("%s", c);
	s = c;
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0, -1, 0) % mod);
	return 0;
}