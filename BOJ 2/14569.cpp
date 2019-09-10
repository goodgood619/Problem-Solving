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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m;
vector<vector<int>> a;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int cnt;
		scanf("%d", &cnt);
		vector<int> temp;
		for (int j = 1; j <= cnt; j++) {
			int num;
			scanf("%d", &num);
			temp.push_back(num);
		}
		sort(temp.begin(), temp.end());
		a.push_back(temp);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int cnt;
		scanf("%d", &cnt);
		vector<int> temp;
		for (int j = 1; j <= cnt; j++) {
			int num;
			scanf("%d", &num);
			temp.push_back(num);
		}
		sort(temp.begin(), temp.end());
		int ans = 0;
		for (int j = 0; j < a.size(); j++) {
			int no = 0;
			for (int k = 0; k < a[j].size(); k++) {
				vector<int>::iterator it = lower_bound(temp.begin(), temp.end(), a[j][k]);
				if (it == temp.end() || *it != a[j][k]) {
					no = 1;
					break;
				}
			}
			if (!no) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}