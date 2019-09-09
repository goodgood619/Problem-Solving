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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int dp[1005][1005];
PP arr[105];
bool visited[105];
int n;
int go(int STR, int INT) {
	int &ret = dp[STR][INT];
	if (ret != -1) return ret;
	int solve = 0;
	vector<int> v;
	int point = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			solve++;
			continue;
		}
		if (STR >= arr[i].first.first || INT >= arr[i].first.second) {
			if (!visited[i]) {
				v.push_back(i);
				visited[i] = true; //이거 안하면 깬걸 또깨니까 ㅇㅇ
				point += arr[i].second;
				solve++;
			}
		}
	}

	ret = solve;
	for (int i = INT,j=point; i <= min(1000, INT + point);i++,j--) {
		ret = max(ret, go(min(1000,STR+j),i));
	}

	for (int i = 0; i < v.size(); i++) visited[v[i]] = false;
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &arr[i].first.first, &arr[i].first.second, &arr[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, 1));
	return 0;
}