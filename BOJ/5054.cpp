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
int main() {
	scanf("%d", &t);
	while (t--) {
		int num;
		cin >> num;
		int Max = -1, Min = 101;
		for (int i = 0; i < num; i++) {
			int a;
			scanf("%d", &a);
			Max = max(Max, a), Min = min(Min, a);
		}
		printf("%d\n", (Max - Min) * 2);
	}
	return 0;
}