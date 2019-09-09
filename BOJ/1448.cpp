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
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
vector<vector<int>> a;
vector<int> v;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--) {
		if (i >= 2) {
			if (v[i] < v[i - 1] + v[i - 2]) {
				printf("%d\n", v[i] + v[i - 1] + v[i - 2]);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}