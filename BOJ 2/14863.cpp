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
int n,k;
ll dp[105][100005];
vector<P> walk,bike;

ll go(int index,int cnt,int k) {
	if (cnt > k) return -1e9;
	if (index >= n) return 0; //끝까지 간경우
	ll &ret = dp[index][cnt];
	if (ret != -1) return ret;
	ret = -1e8;
	ret = max(ret, max(go(index + 1, cnt + walk[index].first, k) + walk[index].second,go(index + 1, cnt + bike[index].first, k) + bike[index].second));// 둘중하나 선택
	return ret;
}
int main() {
	scanf(" %d %d", &n, &k);
	for (int i = 1; i <=n; i++) {
		ll wti, wmo,bti,bmo;
		scanf(" %d %lld %d %lld", &wti, &wmo, &bti, &bmo);
		walk.push_back({ wti,wmo });
		bike.push_back({ bti,bmo });
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n",go(0,0,k));
	return 0;
}