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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n, k;
ll dp[101][21];
int arr[101];
ll go(int index,int total,int depth) {
	if (total < 0 || total>20) return 0;
	if (index == depth) {
		if (total == arr[depth]) return 1;
		else return 0;
	}
	ll &ret = dp[index][total];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(index + 1, total + arr[index], depth);
	ret += go(index + 1, total - arr[index], depth);
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(2,arr[1],n));
	return 0;
}