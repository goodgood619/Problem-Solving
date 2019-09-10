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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m,Max=-1e9-5,Min=1e9+5,a1,a2,a3,a4;
int arr[12];
void dfs(int sum,int idx,int a1,int a2,int a3,int a4) {
	if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0) {
		Max = max(Max, sum), Min = min(Min, sum);
		return;
	}
	if (a1 != 0) dfs(sum + arr[idx], idx+1, a1 - 1, a2, a3, a4);
	if (a2 != 0) dfs(sum - arr[idx], idx+1, a1, a2 - 1, a3, a4);
	if (a3 != 0) dfs(sum*arr[idx], idx+1, a1, a2, a3 - 1, a4);
	if (a4 != 0) dfs(sum / arr[idx], idx+1, a1, a2, a3, a4 - 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
	dfs(arr[0], 1, a1, a2, a3, a4);
	printf("%d\n%d\n", Max, Min);
	return 0;
}