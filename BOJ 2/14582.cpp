
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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int up[9];
int down[9];
int main() {
	for (int i = 0; i < 9; i++) scanf("%d", &up[i]);
	for (int i = 0; i < 9; i++) scanf("%d", &down[i]);
	int upscore = 0,downscore=0;
	bool once = false;
	for (int i = 0; i < 9; i++) {
		upscore += up[i];
		if (upscore > downscore) {
			if (!once) {
				once = true;
			}
		}
		downscore += down[i];
	}
	once == true ? printf("Yes\n") : printf("No\n");
	return 0;
}