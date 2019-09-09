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
typedef pair<pair<int, int>, pair<int, bool>> PPP;
int n, m, k,ans;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
queue<P> q;
bool visited[1000005];
int pre[1000005];
void bfs() {
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (here == 1){
			ans = cnt;
			return;
		}
		if (here % 3 == 0 && !visited[here / 3]) {
			q.push({ here / 3,cnt + 1 });
			visited[here / 3] = true;
			pre[here/3] = here;
		}
		if (here % 2 == 0 && !visited[here / 2]) {
			q.push({ here / 2,cnt + 1 });
			visited[here / 2] = true;
			pre[here/2] = here;
		}
		if (here - 1 > 0 && !visited[here-1]) {
			q.push({ here - 1,cnt + 1 });
			visited[here - 1] = true;
			pre[here-1] = here;
		}
	}
}
int main(){
	scanf("%d", &n);
	q.push({ n,0 });
	bfs();
	printf("%d\n", ans);
	int p = 1;
	vector<int> v;
	while (p != n) {
		v.push_back(p);
		p = pre[p];
	}
	v.push_back(n);
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}