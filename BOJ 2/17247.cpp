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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
typedef unsigned long long lll;

int main() {
	setbuf(stdout, NULL);
	int n, m,fx=-1,fy=-1,sx=-1,sy=-1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int num;
			scanf("%d", &num);
			if (num == 1) {
				if (fx == -1) {
					fx = i, fy = j;
					continue;
				}
				else sx = i, sy = j;
			}
		}
	}
	printf("%d\n", abs(fx - sx) + abs(fy - sy));
	return 0;
}