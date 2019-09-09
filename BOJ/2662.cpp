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
int n, m,Max;
int dp[25][305];
int arr[25][305];
int company[25][305];
int go(int index, int k) {
	if (index >= m) return 0;
	int &ret = dp[index][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int j = 0; j <= n; j++) {
		if (k - j >= 0) {
			int temp = go(index+1, k - j)+arr[index+1][j];
			if (ret <temp) {
				company[index+1][k] = j; //해당기업(index+1)이 남은돈 k원을가치를 최고로하는데 있어서 될수있는 비용 j를 썼다
				ret = temp;
			}
			if (ret < temp) {
				ret = temp;
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int cost;
		scanf("%d", &cost);
		for (int j = 1; j <= m; j++) {
			int cost2;
			scanf("%d", &cost2);
			arr[j][cost] = cost2;
		}
	}
	memset(dp, -1, sizeof(dp));
	Max=go(0, n);
	printf("%d\n", Max);

	vector<int> v;
	int p = n;
	for (int i = 1; i <=m; i++) {
		v.push_back(company[i][p]);
		p-= company[i][p];
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}