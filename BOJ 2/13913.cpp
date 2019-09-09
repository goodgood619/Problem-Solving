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
typedef pair<int, int> P;
typedef pair<pair<ll, ll>, ll> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1, -1,0 };
int goy[4] = { 1,0, 0,-1 };
int n, k, ans = 1e9;
bool visited[100005];
int path[100005];
map<int, int> m;
void bfs() {
	queue<P> q;
	q.push({ n,0 });
	visited[n] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		if (here == k) {
			printf("%d\n", cnt);
			break;
		}
		q.pop();
		for (int i = 1; i < 3; i++) {
			int nx = here + gox[i];
			if (nx < 0 || nx>100000) continue;
			if (!visited[nx]) {
				visited[nx] = true;
				q.push({ nx,cnt + 1 });
				path[nx] = here;
			}
		}
		int nx = here * 2;
		if (nx < 0 || nx>100000) continue;
		if (!visited[nx]) {
			visited[nx] = true;
			q.push({ nx,cnt + 1 });
			path[nx] = here;
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	memset(path, -1, sizeof(path));
	bfs();
	vector<int> ans;
	while (k!=-1) {
		ans.push_back(k);
		k = path[k];
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}