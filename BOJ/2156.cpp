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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int arr[10001];
int dp[10001][4];
int n;
int go(int index,int cnt) {
	if (index <= 0) return 0;
	int &ret = dp[index][cnt];
	if (ret != -1) return ret;
	ret = 0;
	if (cnt == 1) ret = go(index - 1, 2) + arr[index];
	else if (cnt == 2) ret = max({ go(index - 2, 1), go(index - 2, 2),go(index - 2,0)}) + arr[index];
	else ret = max(go(index - 1, 1), go(index - 1, 2));
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", max({ go(n, 1),go(n,2),go(n,0)}));
	return 0;
}