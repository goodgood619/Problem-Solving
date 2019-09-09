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
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
ll dp[12][12][12][12][12][7][7];
int n,total;
int arr[7];
ll go(int one,int two,int three,int four,int five,int pre,int pre2) {
	if (one+two+three+four+five==total) return 1;
	ll &ret = dp[one][two][three][four][five][pre][pre2];
	if (ret != -1) return ret;
	ret = 0;

	if (arr[1] > one && pre != 1 && pre2 != 1) ret += go(one + 1, two, three, four, five, 1, pre);
	if (arr[2] > two && pre != 2 && pre2 != 2) ret += go(one, two + 1, three, four, five, 2, pre);
	if (arr[3] > three && pre != 3 && pre2 != 3) ret += go(one , two, three+1, four, five, 3, pre);
	if (arr[4] > four && pre != 4 && pre2 != 4) ret += go(one, two, three, four+1, five, 4, pre);
	if (arr[5] > five && pre != 5 && pre2 != 5) ret += go(one, two, three, four, five+1, 5, pre);
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		total += arr[i];
	}

	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0,0, 0, 0,0,0,0));
	return 0;
}