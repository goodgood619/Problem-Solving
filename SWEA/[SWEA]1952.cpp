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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int T;
int Case = 1;
int dp[12][365][12][4][2]; // 1일이용권,1달이용권,3달이용권,1년이용권
int price[4];
int arr[12];
int go(int index, int one, int month1, int month3, int year) {
	if (index >= 12) return 0;
	int &ret = dp[index][one][month1][month3][year];
	if (ret != -1) return ret;
	ret = 1e9;
	if (arr[index] == 0) {
		int st = 0;
		for (int i = index; i < 12; i++) {
			if (arr[i] != 0) {
				st = i;
				break;
			}
		}
		if (st == 0) st = 12;
		ret = min(ret, go(st, one, month1, month3, year));
	}
	else {
		ret = min(ret, go(index + 1, one + arr[index], month1, month3, year) + arr[index] * price[0]);
		ret = min(ret, go(index + 1, one, month1 + 1, month3, year)+price[1]);
		ret = min(ret, go(index + 3, one, month1, month3 + 1, year) + price[2]);
		ret = min(ret, go(index + 12, one, month1, month3, year + 1)+price[3]);
	}
	return ret;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 4; i++) {
			scanf(" %d", &price[i]);
		}
		for (int i = 0; i < 12; i++) {
			scanf(" %d", &arr[i]);
		}
		memset(dp, -1, sizeof(dp));
		printf("#%d %d\n", Case++, go(0, 0, 0, 0, 0));
	}
	return 0;
}