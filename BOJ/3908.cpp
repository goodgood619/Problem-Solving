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
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t,n,k;
bool check[1200];
int dp[1200][200][16];
vector<int> coin;
int go(int n, int index,int k) {
	if (n < 0 || k<0) return 0;
	if (n == 0 && k == 0) {
		return 1;
	}
	if (index >= coin.size()) return 0;
	int &ret = dp[n][index][k];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(n - coin[index], index + 1, k - 1)+go(n,index+1,k);
	return ret;
}
int main() {
	for (int i = 2; i <= sqrt(1200); i++) {
		if (check[i]) continue;
		for (int j = i * i; j <= 1200; j += i) {
			check[j] = true;
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		coin.clear();
		for (int i = 2; i <= n; i++) {
			if (!check[i]) coin.push_back(i);
		}
		reverse(coin.begin(), coin.end());
		memset(dp, -1, sizeof(dp));
		printf("%d\n", go(n,0,k));
	}
	return 0;
}
