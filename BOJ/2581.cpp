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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int go(int num) {
	for (int i = 2; i < num; i++) {
		if (num%i == 0) return 0;
	}
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	int sum = 0;
	int idx = 1e9;
	for (int i = n; i <= m; i++) {
		if (i == 1) continue;
		if (go(i)) {
			sum += i;
			idx = min(idx, i);
		}
		else continue;
	}
	if (sum == 0) printf("-1\n");
	else {
		printf("%d\n%d\n", sum, idx);
	}
	return 0;
}