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
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, t;
ll position[100005];
int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		position[i] = (ll)left + ((ll)right)*t;
	}
	ll last = position[n];
	int group = 1;
	for (int i = n - 1; i >= 1; i--) {
		if (last <= position[i]) continue;
		else {
			last = position[i];
			group++;
		}
	}
	printf("%d\n", group);
	return 0;
}