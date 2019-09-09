
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
int t,n;
int dp[1005];
int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
int main() {
	int cnt = 0;
	dp[1] = 2;
	for (int i = 2; i <= 1000; i++) {
		cnt = 0;
		for (int j = 1; j <= i; j++) {
			if (gcd(i, j) == 1) cnt++;
		}
		dp[i] = dp[i - 1] + cnt;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]*2-1);
	}
	return 0;
}