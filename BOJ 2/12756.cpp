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
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	while (1) {
		b -= c, d -= a;
		if (b <= 0 || d <= 0) break;
	}
	if (b <= 0 && d <= 0) printf("DRAW\n");
	else if (b > 0) printf("PLAYER A\n");
	else printf("PLAYER B\n");
	return 0;
}