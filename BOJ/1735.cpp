
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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int a, b, c, d;
int gcd(int a, int b) {
	if (a%b == 0) return b;
	return gcd(b%a, a);
}
int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int mod = gcd(a*d+b*c, b*d);
	printf("%d %d\n", (a*d + b*c) / mod, b*d / mod);
	return 0;
}