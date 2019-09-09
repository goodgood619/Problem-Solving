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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int t, w;
int dp[1005][35][2];
int apple[1005];
int go(int T, int p, int here) {
	if (p > w || T > t) return 0;
	int &ret = dp[T][p][here];
	if (ret != -1) return ret;
	ret = 0;
	if (apple[T] == here) ret = max(ret, go(T + 1, p + 1, 3 - here) + 1); // 2번의 경우
	else ret = max(ret, go(T + 1, p + 1, 3 - here)); // 4번의 경우
	if (apple[T] == here)  ret = max(ret, go(T + 1, p, here) + 1); // 1번의 경우
	else ret = max(ret, go(T + 1, p, here)); // 3번의 경우
	return ret;
}
int main() {
	scanf("%d%d", &t, &w);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &apple[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", max(go(1, 0, 1), go(1, 1, 2))); // 2번위치에서 시작해야 할수도 있음, 이때는 한번움직인 상태에서 시작
	return 0;
}