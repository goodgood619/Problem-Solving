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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;

int main() {
	setbuf(stdout, NULL);
	int a, cura, b, curb, c, curc;
	scanf("%d%d%d%d%d%d", &a, &cura, &b, &curb, &c, &curc);
	int cnt = 0;
	while (1) {
		if (cnt == 100) break;
		if (cnt % 3 == 0) {
			int newb = cura + curb;
			if (newb <= b) {
				curb = newb;
				cura = 0;
			}
			else {
				cura -= (b - curb);
				curb = b;
			}
		}
		else if (cnt % 3 == 1) {
			int newc = curb + curc;
			if (newc <= c) {
				curc = newc;
				curb = 0;
			}
			else {
				curb -= (c - curc);
				curc = c;
			}
		}
		else {
			int newa = curc + cura;
			if (newa <= a) {
				cura = newa;
				curc = 0;
			}
			else {
				curc -= (a - cura);
				cura = a;
			}
		}
		cnt++;
	}
	printf("%d\n%d\n%d\n", cura, curb, curc);
	return 0;
}