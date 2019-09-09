
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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
bool isprime[1000001];
int dp[1001][1001];
int go(int a,int b) {
	if (a > n || b > n) return 0;
	if (a == n && b == n) return 0;
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	string s1 = to_string(a);
	string s2 = to_string(b);
	s1.append(s2);
	int here = stoi(s1);
	ret = 0;
	if (!isprime[here]) ret = max(ret, max(go(a + 1, b)+1, go(a, b + 1)+1));
	else ret = max(ret, max(go(a + 1, b), go(a, b + 1)));
	return ret;
}
int main() {
	setbuf(stdout, NULL);
	for (int i = 2; i <=sqrt(1000000); i++) {
		if (isprime[i]) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			isprime[j] = true;
		}
	}
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, 1)-1);
	return 0;
}