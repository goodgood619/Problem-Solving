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
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
map<double, int> m;
double Rounding(double x, int digit)
{
	return (floor((x)* pow(float(10), digit) + 0.5f) / pow(float(10), digit));
}
int main() {
	scanf("%d", &n);
	if (n == 0) {
		printf("divide by zero\n");
		return 0;
	}
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		double num;
		scanf("%lf", &num);
		sum += num;
		m[num]++;
	}
	sum /= n;
	map<double, int>::iterator it;
	double d = 0;
	for (it = m.begin(); it != m.end(); it++) {
		d+=it->first*((double)(it->second) / (double)n);
	}

	double ans = sum / d;
	printf("%.2lf\n", Rounding(ans, 3));
	return 0;
}