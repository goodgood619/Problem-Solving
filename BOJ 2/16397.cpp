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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int start, cnt, en,ok,ans;
bool visited[100005];
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
void bfs(int start, int cnt, int en) {
	queue<P> q;
	q.push({ start,0 });
	visited[start] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int curcnt = q.front().second;
		q.pop();
		if (curcnt > cnt) {
			return;
		}
		if (here == en ){
			ans = curcnt;
			ok = 1;
			return;
		}
		int na = here + 1;
		int nb = here * 2;
		if (!visited[na] && na<100000) {
			visited[na] = true;
			q.push({ na,curcnt + 1 });
		}
		if (nb >= 100000) continue;
		if (here == 0) continue;
		int c = 1;
		int p = nb;
		while (p > 0) {
			p /= 10;
			c *= 10;
		}
		c /= 10;
		nb -= c;
		if (!visited[nb] &&  nb < 100000) {
			visited[nb] = true;
			q.push({ nb,curcnt + 1 });
		}
	}
}
int main() {
	scanf("%d%d%d", &start, &cnt, &en);
	bfs(start, cnt, en);
	if (ok) printf("%d\n", ans);
	else printf("ANG\n");
	return 0;
}