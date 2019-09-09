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
#define mod 1000000009
#define lim 1000000000
typedef pair < int,int > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int ccw(P A, P B, P C) {
	int x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
}
int main(void) {
	int x1, y1, x2, y2, x3, y3;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	int CCW = ccw(P{ x1,y1 }, P{ x2,y2 }, P{ x3,y3 });
	if (CCW > 0) printf("1\n");
	else if (CCW < 0) printf("-1\n");
	else printf("0\n");
	return 0;
}