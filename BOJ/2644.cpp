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
int n,st,en,m;
vector<vector<int>> a;
int bfs(int st, int en) {
	queue<P> q;
	q.push({ st,0 });
	bool visited[105] = { false, };
	visited[st] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		if (here == en) return cnt;
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}
	return -1;
}
int main(void) {
	scanf("%d", &n);
	scanf("%d%d", &st, &en);
	scanf("%d", &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	printf("%d\n",bfs(st, en));
	return 0;
}