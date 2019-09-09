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
map<int, int> checkx,checky;
int main() {
	for (int i = 0; i < 3; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		checkx[x]++,checky[y]++;
	}
	map<int, int>::iterator it, it2;
	for (it = checkx.begin(); it != checkx.end(); it++) {
		if (it->second == 1) printf("%d ", it->first);
	}
	for (it2 = checky.begin(); it2 != checky.end(); it2++) {
		if (it2->second == 1) printf("%d", it2->first);
	}
	return 0;
}