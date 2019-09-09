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
#include <deque>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int arr[100005];
int dp[100005];
int n;
int main(){
	while (scanf("%d", &n) != EOF) {
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		dp[0] = -98765;
		int en = 0;
		for (int i = 1; i <= n; i++) {
			int *idx = lower_bound(dp + 1, dp + en + 1, arr[i]);
			*idx = arr[i];
			if (idx == dp + en + 1) en++;
		}
		printf("%d\n", en);
	}
	
	return 0;
}