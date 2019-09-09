#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,Max=-1e9;
int dp[100005];
priority_queue<P, vector<P>, greater<P>> pq;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int num;
		scanf("%d", &num);
		if (i == 1){
			dp[1] = num;
			Max = max(Max, dp[1]);
			continue;
		}
		else{
			dp[i] = dp[i - 1] + num;
			if (dp[i] < num) dp[i] = num;
			Max = max(Max, dp[i]);
		}
	}
	printf("%d\n", Max);
	return 0;
}

