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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &t);
	while (t--) {
		double x1, y1, r1, x2, y2, r2;
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);
		double d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) printf("-1\n");
			else printf("0\n");
		}
		else {
			if (abs(r1 - r2) < d && d < abs(r1 + r2)) printf("2\n");
			else if (d == abs(r1 - r2) || d == abs(r1 + r2)) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}