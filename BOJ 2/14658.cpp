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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int,int> P;
typedef pair<ll, pair<ll,ll>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m, l, k;
P star[105];
int main() {
	scanf("%d%d%d%d", &n, &m, &l, &k);
	for (int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		star[i].first = x;
		star[i].second = y;
	}
	int Max = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			int cnt = 0;
			for (int p = 1; p <= k; p++) {
				if (star[i].first <= star[p].first && star[p].first <= star[i].first + l && star[j].second <= star[p].second
					&& star[p].second <= star[j].second + l) {
					cnt++;
				}
			}
			Max = max(Max, cnt);
		}
	}
	printf("%d\n", k - Max);
	return 0;
}