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
	for (int i = 1; i <= l; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		star[i].first = x;
		star[i].second = y;
	}
	sort(star + 1, star + l + 1);
	if (l == 1) {
		printf("%d %d\n", 0, m);
		printf("1\n");
		return 0;
	}
	int Max = 0;
	int x, y;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			int cnt = 0;
			for (int p = 1; p <= l; p++) {
				if (star[i].first <= star[p].first && star[p].first <= star[i].first + k && star[j].second <= star[p].second
					&& star[p].second <= star[j].second + k) {
					cnt++;
				}
			}
			if (Max < cnt) {
				if (star[i].first + k > n || star[i].second + k > m) {
					int p= star[i].first + k,q = star[j].second + k;
					if (star[i].first + k > n) {
						while (p > n) {
							p--;
						}
						if (p-k < 0) continue;
					}
					if(star[j].second+k>m){
						while (q > m) {
							q--;
						}
						if (q-k < 0) continue;
					}
					x = p-k;
					y = q;
				}
				else {
					x = star[i].first;
					y = star[j].second + k;
				}
				Max = max(Max, cnt);

			}
		}
	}
	printf("%d %d\n",x, y);
	printf("%d\n", Max);
	return 0;
}