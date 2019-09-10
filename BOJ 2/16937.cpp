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
#define mod 1000000009
#define lim 1000000000
typedef pair <int, int > P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,-1,1,1,-1 };
int n, m, k,Max;
vector<P> v,temp;
int board[102][102];
bool visited[102];
void dfs(int index,int cnt,int depth) {
	if (cnt == depth) {
		int x1 = temp[0].first, y1 = temp[0].second, x2 = temp[1].first, y2 = temp[1].second;
		if (x1 + x2 <= n && max(y1,y2) <= m) Max = max(Max, x1*y1 + x2 * y2);
		if(x1+y2<=n && max(y1,x2)<=m) Max = max(Max, x1*y1 + x2 * y2);
		if(y1+x2<=n && max(x1,y2)<=m)Max = max(Max, x1*y1 + x2 * y2);
		if(y1+y2<=n && max(x1,x2)<=m)Max = max(Max, x1*y1 + x2 * y2);
		if (x1 + x2 <= m && max(y1, y2) <= n) Max = max(Max, x1*y1 + x2 * y2);
		if (x1 + y2 <= m && max(y1, x2) <= n) Max = max(Max, x1*y1 + x2 * y2);
		if (y1 + x2 <= m && max(x1, y2) <= n)Max = max(Max, x1*y1 + x2 * y2);
		if (y1 + y2 <= m && max(x1, x2) <= n)Max = max(Max, x1*y1 + x2 * y2);
		return;
	}
	for (int i = index; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back({ v[i].first,v[i].second });
			dfs(i + 1, cnt + 1, depth);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		int h, w;
		scanf("%d%d", &h, &w);
		v.push_back({ h,w });
	}
	dfs(0, 0, 2);
	printf("%d\n", Max);
	return 0;
}