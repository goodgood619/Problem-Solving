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
int dp[50005][4]; // n번째 객실의차가, 1,2,3번 중의 소형기관차가 이끌었을때 운행할수있는 최대 손님수
int sum[50005];
int n, m;
int go(int index,int car) {
	if (car <= 0) return 0;
	if (index < m) return sum[index]; // 남은객실의 갯수보다 1대의 차가 끌수있는 객실의 갯수가 더 많을때
	int &ret = dp[index][car];
	if (ret != -1) return ret;
	ret = 0;
	// n번째객실을 선택할지말지로 나뉜다!!
	ret = max(ret, max(go(index - 1, car), go(index - m, car - 1) + sum[index] - sum[index - m]));
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		sum[i] = sum[i - 1] + num;
	}
	scanf("%d", &m);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n, 3));
	return 0;
}