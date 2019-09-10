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
#define mod 1000000009
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1, -1,0 };
int goy[4] = {1,0, 0,-1 };
vector<double> v;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double d;
		scanf("%lf", &d);
		v.push_back(d);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 7; i++) {
		printf("%.3lf\n", v[i]);
	}
	return 0;
}