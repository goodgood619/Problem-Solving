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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int t;
int Case = 1;
int main() {
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int cnt[100] = { 0, };
		vector<int> a, b,ans;
		for (int i = 1; i <= n; i++) {
			a.push_back(i);
		}
		for (int i = 1; i <= m; i++) {
			b.push_back(i);
		}
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				cnt[a[i] + b[j]]++;
			}
		}
		int Max = 0;
		for (int i = 2; i <= 99; i++) {
			Max = max(Max, cnt[i]);
		}
		for (int i = 2; i <= 99; i++) {
			if (Max == cnt[i]) {
				ans.push_back(i);
			}
		}
		printf("#%d ", Case++);
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}