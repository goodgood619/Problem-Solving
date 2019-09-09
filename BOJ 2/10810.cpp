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
int t, Case = 1, n, m;
int ball[101];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int p, q, r;
		scanf(" %d%d%d", &p, &q, &r);
		for (int j = p; j <= q; j++) {
			ball[j] = r;
		}
	}
	for (int i = 1; i <= n; i++)  printf("%d ", ball[i]);
	return 0;
}