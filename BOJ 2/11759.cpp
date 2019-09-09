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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int, pair<ll, char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int s, v1, v2;
int main() {
	scanf("%d%d%d", &s, &v1, &v2);
	int mok = s / v1;
	int p = s;
	int Min = 1e9;
	int ans1 = 0, ans2 = 0;
	do{
		int temp = p;
		p -= (mok*v1);
		if (p%v2 == 0) {
			if (Min > p / v2 + mok) {
				Min = min(Min, p / v2 + mok);
				ans2 = p / v2;
				ans1 = mok;
			}
		}
		p = temp;
	} while (mok--);
	if (ans1 == 0 && ans2 == 0) printf("Impossible\n");
	else printf("%d %d\n", ans1, ans2);
	return 0;
}