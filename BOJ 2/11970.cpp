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
int gox[4] = { 1, 0,0,-1 };
int goy[4] = { 0, 1,-1,0 };
int a,b,c,d;
int num[105];
int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for (int i = a; i <= b; i++) num[i]++;
	for (int i = c; i <= d; i++) num[i]++;
	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		if (num[i] > 0) ans++;
	}
	ans--;
	if (b < c) {
		ans--;
	}
	if (d < a) {
		ans--;
	}
	printf("%d\n", ans);
	return 0;
}