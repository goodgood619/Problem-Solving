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
#define mod 123456789
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int n;
int isprime[40005];
int dp[40005];
vector<int> v;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= 40000; i++)isprime[i] = i;
	for (int i = 2; i <= sqrt(40000); i++){
		if (isprime[i] == 0) continue;
		for (int j = i*i; j <= 40000; j += i) {
			isprime[j] = 0;
		}
	}
	for (int i = 2; i <= 40000; i++) {
		if (isprime[i]) v.push_back(i);
	}
	dp[0] = 1;
	for (int j = 0; j <v.size(); j++) {
		for (int i = 2; i <=n; i++) {
			if (i - v[j] >= 0) {
				dp[i] += dp[i - v[j]];
				dp[i] %= mod;
			}
		}
	}
	printf("%d\n", dp[n] % mod);
	return 0;
}