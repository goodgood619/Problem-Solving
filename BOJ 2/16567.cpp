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
typedef pair<pair<int, int>, pair<int, char>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n, m;
int arr[1000001];
int parent[1000001];
int find(int u) {
	if (parent[u] == u) return u;
	else return parent[u] = find(parent[u]);
}
void uni(int u,int v) {
	u = find(u);
	v = find(v);
	if (u == v)return;
	parent[u] = v;
}
int main() {
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 1 && arr[i - 1] == 1) uni(i, i - 1);
		else if (arr[i] == 1 && arr[i - 1] == 0) ans++;
	}
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++) {
		int c;
		scanf("%d", &c);
		if (c == 0) {
			printf("%d\n", ans);
		}
		else {
			int num;
			scanf("%d", &num);
			if (arr[num] == 1) continue;
			if (arr[num] == 0) {
				arr[num] = 1;
				ans++;
			}
			if (arr[num - 1] == 1) {
				int pre = find(num - 1);
				int here = find(num);
				if (pre != here) {
					uni(num, num - 1);
					ans--;
				}
			}
			if (arr[num + 1] == 1) {
				int here = find(num);
				int next = find(num + 1);
				if (here != next) {
					uni(here, next);
					ans--;
				}
			}
			arr[num] = 1;
		}
	}
	return 0;
}