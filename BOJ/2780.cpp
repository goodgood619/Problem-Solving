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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int t;
int dp[1005][10];
int go(int index, int num,int depth) {
	if (index >=depth) return 1;
	int &ret = dp[index][num];
	if (ret != -1) return ret;
	ret = 0;
	if (num == 0) {
		ret += go(index + 1, 7, depth);
	}
	else if (num == 1) {
		for (int i = 2; i <= 4; i += 2) {
			ret+=go(index+1,i,depth);
		}
	}
	else if (num == 2) {
		for (int i = 1; i <= 5; i += 2) {
			ret += go(index + 1, i, depth);
		}
	}
	else if (num == 3) {
		for (int i = 2; i <= 6; i += 4) {
			ret += go(index + 1, i, depth);
		}
	}
	else if (num == 4) {
		ret += go(index + 1, 1, depth);
		ret += go(index + 1, 5, depth);
		ret += go(index + 1, 7, depth);
	}
	else if (num == 5) {
		for (int i = 2; i <= 8; i += 2) {
			ret += go(index + 1, i, depth);
		}
	}
	else if (num == 6) {
		ret += go(index + 1, 3, depth);
		ret += go(index + 1, 5, depth);
		ret += go(index + 1, 9, depth);
	}
	else if (num == 7) {
		for (int i = 0; i <= 8; i += 4) {
			ret += go(index + 1, i, depth);
		}
	}
	else if (num == 8) {
		for (int i = 5; i <= 9; i += 2) {
			ret += go(index + 1, i, depth);
		}
	}
	else {
		for (int i = 6; i <= 8; i += 2) {
			ret += go(index + 1, i, depth);
		}
	}
	ret %= 1234567;
	return ret;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int n;
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		int ans = 0;
		int mod = 1234567;
		for (int i = 0; i < 10; i++) {
			ans += go(1, i,n);
			ans %= mod;
		}
		printf("%d\n", ans%mod);
	}
	return 0;
}