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
#define mod 1000000009
typedef pair<int,int> P;
typedef pair<pair<ll, ll>, ll> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1, -1,0 };
int goy[4] = {1,0, 0,-1 };
int n, k, ans = 1e9;
bool visited[100005];
map<int, int> m;
void bfs() {
	queue<P> q;
	q.push({ n,0 });
	visited[n] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[here] = true;
		if (here == k) {
			if (ans >= cnt) {
				ans = cnt;
				m[cnt]++;
			}
		}
		if (here>=0 && here + 1 <= 100000 &&!visited[here+1]) q.push({ here + 1,cnt + 1 });
		if (here - 1 >= 0 && here <= 100000 && !visited[here-1]) q.push({ here - 1,cnt + 1 });
		if (here >= 0 && here * 2 <= 100000 && !visited[here*2]) q.push({ here * 2,cnt + 1 });
	}
}
int main() {
	scanf("%d%d",&n, &k);
	if (n == k) {
		printf("0\n1\n");
		return 0;
	}
	bfs();
	printf("%d\n%d\n", ans, m[ans]);
	return 0;
}