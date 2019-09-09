#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,Max=-1e9;
int dp[300005];
priority_queue<P, vector<P>, greater<P>> pq;
vector<int> coin;
vector<int> coin2;
int go(int k) {
	int &ret = dp[k];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i <coin2.size(); i++) {
		if (k - coin2[i]>= 0) {
			ret = min(ret, go(k -coin2[i])+1);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	coin.push_back(1);
	int sum = 1;
	for (int i=2;;i++){
		sum += i;
		if (sum <= n) coin.push_back(sum);
		else break;
	}
	sum = 0;
	for (int i = 0; i < coin.size(); i++) {
		sum += coin[i];
		coin2.push_back(sum);
	}

	printf("%d\n", go(n));
	return 0;
}