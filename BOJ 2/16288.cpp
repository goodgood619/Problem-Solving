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
int n, k;
int arr[105];
int dp[105];
int path[105];
bool visited[105];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int cnt = 0;
	while (1) {
		int Max = 0;
		bool check = false;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			if (Max == 0 || Max < arr[i]) {
				Max = arr[i];
				check = true;
				visited[i] = true;
			}
		}
		if (!check) break;
		cnt++;
	}
	int nocheck = 0;
	if (cnt >k) nocheck = 1;
	nocheck ? printf("NO") : printf("YES");
	return 0;
}