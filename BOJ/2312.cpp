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
typedef pair<int, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		map<int, int> m;
		int p = n;
		int mod = 2;
		while (p > 1) {
			if (p%mod == 0) {
				m[mod]++;
				p /= mod;
				mod = 2;
			}
			else mod++;
		}
		map<int, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			printf("%d %d\n", it->first, it->second);
		}
	}
	return 0;
}