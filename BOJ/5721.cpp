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
typedef pair<ll,ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int m, n;
int dp1[100005]; //행관리
int dp2[100005]; //열관리
int arr[100005];
int go2(int here, int k) {
	if (here>= n*(k + 1)) return 0; //열이 끝났을 경우
	int &ret = dp2[here];
	if (ret != -1) return ret;
	ret = max(go2(here + 1, k) , go2(here + 2, k) + arr[here]);
	return ret;
}
int go(int here) {
	if (here >= m) return 0; //행이 끝났을경우
	int &ret = dp1[here];
	if (ret != -1) return ret;
	ret = max(go(here + 1), go(here + 2) + go2(here*n, here));
	return ret;
}
int main() {
	while (1) {
		scanf(" %d %d", &m, &n);
		if (m == 0 && n == 0) {
			break;
		}
		memset(arr, 0, sizeof(arr));
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));
		for (int i = 0; i < m*n; i++) {
			scanf(" %d", &arr[i]);
		}
		printf("%d\n", go(0));
	}
	return 0;
}