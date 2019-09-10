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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1, n;
int main() {
	ll a;
	scanf("%lld", &a);
	if (a % 8 >= 1 && a % 8 <= 5) printf("%lld\n", a % 8);
	else if (a % 8 == 6) printf("4\n");
	else if (a % 8 == 7) printf("3\n");
	else if (a % 8 == 0) printf("2\n");
	return 0;
}