#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int a, b, c,total,ok;
int cnt[3];
bool visited[1505][1505];
// x+x, y-x(x:작은쪽, y:큰쪽)
int dfs(int a, int b, int c) {
	cnt[0] = a, cnt[1] = b, cnt[2] = c;
	sort(cnt,cnt+3);
	a = cnt[0], b = cnt[1], c = cnt[2];
	if (visited[a][b]) {
		return 0;
	}
	visited[a][b] = true;
	if (a == b && b == c ) {
		ok = 1;
		return 1;
	}
	//visited[v[0]][v[1]] = true;
	if (ok != 1) {
		if (a < b) {
			if (dfs(a + a, b - a, c)) return 1;
		}
		if (a < c) {
			if (dfs(a + a, b, c - a)) return 1;
		}
		if (b < c) {
			if (dfs(a, b + b, c - b)) return 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d %d %d", &a, &b, &c);
	if (dfs(a, b, c)) printf("1\n");
	else printf("0\n");
	return 0;
}