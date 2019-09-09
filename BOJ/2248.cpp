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
typedef pair < ll, ll > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll dp[33][33];
int n, k,total;
ll l;
void go2(int n, int zero,int one, ll l, string s) {
	if (l == 1) {
		printf("%s", s.c_str());
		for (int i = 0; i < total - s.size(); i++) {
			printf("0");
		}
		printf("\n");
		exit(0);
	}
	if (one == 0) {
		printf("%s", s.c_str());
		for (int i = 0; i < total - s.size(); i++) {
			printf("0");
		}
		printf("\n");
		exit(0);
	}
	ll ret = 0;
	for (int i = 0; i <= one; i++) { //앞자리가 0이된다고 가정
		ret += dp[n-1][i];
	}
	if (ret >= l) { //0을채운다
		go2(n-1, zero - 1, one, l, s + "0");
	}
	else { //1을채운다
		go2(n-1, zero, one - 1, l - ret, s + "1");
	}
}
int main() {
	for (int i = 0; i <= 31; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= 31; i++) {
		for (int j = 1; j <= 31; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	scanf("%d%d%d", &n, &k, &l);
	total = n;
	go2(n,n-k,k,l,"");
	return 0;
}