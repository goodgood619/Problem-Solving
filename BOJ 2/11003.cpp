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
int n, l;
deque<P> d;
int main() {
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		while (!d.empty() && d.front().second <= i - l) d.pop_front();
		while (!d.empty() && d.back().first >= num) d.pop_back();
		d.push_back({ num,i });
		printf("%d ", d.front().first);
	}
	return 0;
}