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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n, cost, h, p;
int hotel[18];
vector<vector<int>> week;
int main() {
	scanf("%d%d%d%d", &n, &cost, &h, &p);
	week.resize(h + 1);
	for (int i = 0; i < h; i++) {
		scanf("%d", &hotel[i]);
		for (int j = 0; j < p; j++) {
			int num;
			scanf("%d", &num);
			week[i].push_back(num);
		}
	}
	int Min = 1e9;
	for (int i = 0; i < week.size(); i++) {
		for (int j = 0; j < week[i].size(); j++) {
			int ok = week[i][j];
			if (ok < p) continue;
			else {
				if(cost>=hotel[i]*n) Min = min(Min, hotel[i] * n);
			}
		}
	}
	Min == 1e9 ? printf("stay home\n") : printf("%d\n", Min);
	return 0;
}