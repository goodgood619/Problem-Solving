#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define inf INT_MAX
int n,k;
int coin[25];
int dp[10005];
typedef pair<int, int> P;
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) { scanf("%d", &coin[i]);}
		scanf("%d", &k);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (j - coin[i] >= 0) {
					dp[j] += dp[j - coin[i]];
				}
			}
		}
		printf("%d\n", dp[k]);
	}
	return 0;
}