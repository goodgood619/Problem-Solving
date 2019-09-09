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
P arr[101];
int n;
int dp[101];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
	for (int i = 1; i <= n; i++) {
		if (arr[i].first > arr[i].second) swap(arr[i].first, arr[i].second);
	}
	sort(arr + 1, arr + n + 1);
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i].first >=arr[j].first && arr[i].second >= arr[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
				Max = max(Max, dp[i]);
			}
		}
	}
	printf("%d\n", Max);
	return 0;
}