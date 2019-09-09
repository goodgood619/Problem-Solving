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
using namespace std;
typedef long long ll;
int n, k;
typedef pair<int, int> P;
P bag[105];
int dp[105][100005];
#define INF 1e9
int go(int n,int k){
	if (k <= 0) return 0;
	if (n <= 0) return 0;
	int &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(n - 1, k));
		if (k - bag[n].first >= 0) {
			ret=max(ret,go(n-1,k - bag[n].first)+bag[n].second);
		}
	return ret;
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &bag[i].first,&bag[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n,k));
	return 0;
}