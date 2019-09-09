#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
using namespace std;
int n, m, cnt,Case=1;
typedef pair<int, int> P;
typedef long long ll;
ll arr[100005][4];
ll dp[100005][4];
#define inf 1e9
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 1; i <= 100000; i++) {
			for (int j = 1; j <= 3; j++) {
				dp[i][j] = 1e9;
			}
		}
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf(" %lld", &arr[i][j]);
			}
		}
		dp[1][2] = arr[1][2];
		dp[1][3] = arr[1][2] + arr[1][3];
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if (j == 1) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]+arr[i][j]) ;
					dp[i][j] = min(dp[i][j], dp[i-1][j]+arr[i][j]);
				}
				else if (j == 2) {
					dp[i][j] = min(dp[i][j], dp[i-1][j - 1] + arr[i][j]);
					dp[i][j] = min(dp[i][j], dp[i-1][j + 1] + arr[i][j]) ;
					dp[i][j] = min(dp[i][j], dp[i-1][j] + arr[i][j]);
					dp[i][j] = min(dp[i][j], dp[i][j-1] + arr[i][j]);
				}
				else if (j == 3) {
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + arr[i][j]) ;
					dp[i][j] = min(dp[i][j], dp[i-1][j - 1] + arr[i][j]);
					dp[i][j] = min(dp[i][j], dp[i-1][j] + arr[i][j]);
				}
			}
		}
		printf("%d. %lld\n",Case,dp[n][2]);
		Case++;
	}

	return 0;
}