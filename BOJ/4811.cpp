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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
ll dp[35];
int n;
int main() {
	dp[1] = 1,dp[2]=2,dp[3]=5;
	for (int i = 4; i <= 30; i++) { //카탈란수!!: 
		ll here = 1;
		ll temp = 1;
		for (int j = i + 2; j <= 2 * i; j++) {
			temp *= j;
			temp /= here;
			here++;
		}
		temp /= here;
		dp[i] = temp;
	}

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		printf("%lld\n", dp[n]);
	}
	return 0;
}