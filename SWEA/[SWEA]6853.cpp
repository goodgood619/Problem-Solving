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
int T;
int main() {
	scanf("%d", &T);
	int Case = 1;
	while (T--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int n;
		scanf("%d", &n);
		int in = 0, meet = 0, out = 0;
		for (int i = 1; i <= n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x > x1 && x<x2 && y>y1 && y < y2) {
				in++;
			}
			else if ((x==x1 && y>=y1 && y<=y2) ||(x==x2 &&y>=y1 && y<=y2) || (y==y1 && x>=x1 && x<=x2) || (y==y2 && x>=x1 &&x<=x2)) {
				meet++;
			}
			else {
				out++;
			}
		}
		printf("#%d %d %d %d\n", Case++, in, meet, out);
	}
	return 0;
}