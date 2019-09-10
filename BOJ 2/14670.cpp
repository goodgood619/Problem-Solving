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
typedef pair<int, pair<ll, char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
map<int, int> mm;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int key, value;
		scanf("%d%d", &key, &value);
		mm[key] = value;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int cnt;
		int no = 0;
		scanf("%d", &cnt);
		vector<int> v;
		for (int j = 1; j <= cnt; j++) {
			int num;
			scanf("%d", &num);
			if (mm.count(num) == 0) {
				no = 1;
			}
			else v.push_back(mm[num]);
		}
		if (no) printf("YOU DIED\n");
		else {
			for (int i = 0; i < v.size(); i++) {
				printf("%d ", v[i]);
			}
			printf("\n");
		}
	}
	return 0;
}