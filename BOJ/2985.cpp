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
int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	if (a + b == c) {
		printf("%d+%d=%d\n", a, b, c);
		return 0;
	}
	else if (a - b == c) {
		printf("%d-%d=%d\n", a, b, c);
		return 0;
	}
	else if (a*b == c) { printf("%d*%d=%d\n", a, b, c);  return 0; }
	else if (a / b == c) {
		printf("%d/%d=%d\n", a, b, c); return 0;
	}
	else if (a == b + c) { printf("%d=%d+%d\n", a, b, c); return 0; }
	else if (a == b - c) {
		printf("%d=%d-%d\n", a, b, c); return 0;
	}
	else if (a == b * c) {
		printf("%d=%d*%d\n", a, b, c); return 0;
	}
	else if (a == b / c) { printf("%d=%d/%d\n", a, b, c); return 0; }

	return 0;
}