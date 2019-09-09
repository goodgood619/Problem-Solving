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
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
double x,y, c;
int main() {
	while (scanf("%lf%lf%lf", &x, &y, &c) != EOF) {
		double left = 0.0;
		double right = min(x,y);
		while (right - left >1e-6) {
			double mid = (left + right) / (2.0); //아래 너비값이라고 가정(w)
			double rheight = sqrt(y*y - mid * mid);
			double lheight = sqrt(x*x - mid * mid);
			double gy = (lheight*rheight) / (lheight + rheight);
			if (gy > c) {
					left = mid;
			}
			else right = mid;
		}
		printf("%.3lf\n",left);
	}
	return 0;
}