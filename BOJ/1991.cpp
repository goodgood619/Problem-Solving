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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<vector<P>> a;
int n;
void dfs1(int here) {
	printf("%c", here + 'A');
	if (a[here][0].first != -1) dfs1(a[here][0].first);
	if (a[here][0].second != -1) dfs1(a[here][0].second);
}
void dfs2(int here) {
	if (a[here][0].first != -1) dfs2(a[here][0].first);
	printf("%c", here + 'A');
	if (a[here][0].second != -1) dfs2(a[here][0].second);
}
void dfs3(int here) {
	if (a[here][0].first != -1) dfs3(a[here][0].first);
	if (a[here][0].second != -1) dfs3(a[here][0].second);
	printf("%c", here + 'A');
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		char here, left, right;
		scanf(" %c %c %c", &here, &left, &right);
		if (left == '.' && right != '.') {
			a[here - 'A'].push_back({ -1,right-'A' });
		}
		else if (left != '.' && right == '.') {
			a[here - 'A'].push_back({ left - 'A',-1 });
		}
		else if (left == '.' && right == '.') {
			a[here - 'A'].push_back({ -1,-1});
		}
		else {
			a[here - 'A'].push_back({ left - 'A',right - 'A' });
		}
	}
	dfs1(0);
	printf("\n");
	dfs2(0);
	printf("\n");
	dfs3(0);
	return 0;
}