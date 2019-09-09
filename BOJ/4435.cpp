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
	scanf("%d", &t);
	while (t--) {
		int a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6, b7;
		scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5,&a6);
		scanf("%d%d%d%d%d%d%d", &b1, &b2, &b3, &b4, &b5, &b6,&b7);
		int temp1 = a1 + 2 * a2 + 3 * a3 + 3 * a4 + 4 * a5 + 10 * a6;
		int temp2 = b1 + 2 * b2 + 2 * b3 + 2 * b4 + 3 * b5 + 5 * b6 + 10 * b7;
		if (temp1 > temp2) printf("Battle %d: Good triumphs over Evil\n", Case++);
		else if (temp1 == temp2) printf("Battle %d: No victor on this battle field\n", Case++);
		else printf("Battle %d: Evil eradicates all trace of Good\n", Case++);
	}
	return 0;
}