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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, l;
PPP road[105];
int main() {
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &road[i].first, &road[i].second.first, &road[i].second.second);
	}
	road[n + 1].first = l;
	int ti = 0;
	for (int i = 1; i <= n+1; i++) {
		ti += road[i].first - road[i - 1].first;
		if (i == n + 1) break;
		int simul = 0;
		int flag = 0;
		while (1) {
			int p = simul;
			if (!flag) {
					simul += road[i].second.first;
					flag = 1;
			}
			else {
					simul += road[i].second.second;
					flag = 0;
			}
			if (simul > ti) {
					break;
			}
		}
		if (flag) {
				ti += simul - ti;
		}
	}
	printf("%d\n", ti);
	return 0;
}