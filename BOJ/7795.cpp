
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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;

int main() {
	setbuf(stdout, NULL);
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> v1, v2;
		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			v1.push_back(num);
		}
		for (int i = 1; i <= m; i++) {
			int num;
			scanf("%d", &num);
			v2.push_back(num);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int ans = 0;
		for (int i = 0; i < v2.size(); i++) {
			vector<int>::iterator it = upper_bound(v1.begin(), v1.end(), v2[i]);
			if (it == v1.end()) continue;
			else ans += v1.end()-it;
		}
		printf("%d\n", ans);
	}
	return 0;
}
