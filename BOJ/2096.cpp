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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int dp[4];
int dp2[4];
int temp[4];
int temp2[4];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			int num;
			scanf("%d", &num);
			if (i == 1) {
				temp[j] = num;
				temp2[j] = num;
				continue;
			}
			else {
				if (j == 1) {
					int p = num;
					num += max(temp[1], temp[2]);
					p += min(temp2[1], temp2[2]);
					dp[1] = num;
					dp2[1] = p;
				}
				else if (j == 2) {
					int p = num;
					num += max(temp[3], max(temp[1], temp[2]));
					p+= min(temp2[3], min(temp2[1], temp2[2]));
					dp[2] = num;
					dp2[2] = p;
				}
				else if (j == 3) {
					int p = num;
					num += max(temp[3], temp[2]);
					p += min(temp2[3], temp2[2]);
					dp[3] = num;
					dp2[3] = p;
				}
			}
		}
		if (i >= 2) {
			for (int k = 1; k <= 3; k++) {
				temp[k] = dp[k];
				temp2[k] = dp2[k];
			}
		}
	}
	if (n == 1) {
		for (int k = 1; k <= 3; k++) {
			dp[k] = temp[k];
			dp2[k] = temp2[k];
		}
	}
	int ans1 = 0, ans2 = 1e9;
	for (int i = 1; i <= 3; i++) {
		ans1 = max(ans1, dp[i]);
		ans2 = min(ans2, dp2[i]);
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}