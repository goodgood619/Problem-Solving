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
int m, k, total;
int main() {
	scanf("%d", &m);
	vector<int> v;
	for (int i = 1; i <= m; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
		total += num;
	}
	scanf("%d", &k);
	double ans = 1;
	double result = 0;
	for (int i = 0; i < v.size(); i++) {
		int here = v[i];
		int cnt = 0;
		int p = total;
		ans = 1;
		if (here < k) continue;
		for (int j = here;j>=1; j--) {
			ans *= (double)(j) / p;
			p--;
			cnt++;
			if (cnt == k) break;
		}
		result += ans;
	}
	printf("%.10lf\n", result);
	return 0;
}