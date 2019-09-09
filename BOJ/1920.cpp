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
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m;
int main() {
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), num);
		if (it == v.end()) printf("0\n");
		else {
			*it == num ? printf("1\n") : printf("0\n");
		}
	}
	return 0;
}