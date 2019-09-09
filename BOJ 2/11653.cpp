
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
int n;
int main() {
	scanf("%d", &n);
	int p = 2;
	vector<int> v;
	while (n > 1) {
		if (n%p == 0) {
			v.push_back(p);
			n /= p;
			p = 2;
		}
		else p++;
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}