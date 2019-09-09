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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int f, s, g, u, d;
bool visited[1000005];
int bfs(int st, int en) {
	queue<P> q;
	visited[st] = true;
	q.push({ st,0 });
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (here == en) return cnt;
		int up = here + u, down = here - d;
		if (!visited[up] && up <= 1000000) {
			visited[up] = true;
			q.push({ up,cnt + 1 });
		}
		if (!visited[down] && down >= 1) {
			visited[down] = true;
			q.push({ down,cnt + 1 });
		}
	}
	return -1;
}
int main(void) {
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	int ans=bfs(s, g);
	ans == -1 ? printf("use the stairs\n") : printf("%d\n", ans);
	return 0;
}