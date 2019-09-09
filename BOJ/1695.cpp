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
#define mod 1000000007
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int arr[5005];
int dp[5005][5005];
int go(int s, int e) {
	if (s > e) return 0;
	int &ret = dp[s][e];
	if (ret != -1) return ret;
	ret = 1e9;
	if (arr[s] != arr[e]) { //다르다면, s를 한칸 진행을 하던지, e를 한칸을 진행을 하던지
		ret = min(ret, min(go(s + 1, e) + 1, go(s, e - 1) + 1));
	}
	else ret = min(ret, go(s + 1, e - 1)); //같으면 그냥 둘다 이동시키면 된다
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &arr[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, n));
	return 0;
}