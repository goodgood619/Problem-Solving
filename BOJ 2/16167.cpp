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
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
P dist[105];
bool visited[105];
vector<vector<P>> a;
int path[105][105];
vector<int> v;
void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		dist[i].first = 1e9;
		dist[i].second = 1e9;
	}
	dist[1].first = 0;
	dist[1].second = 1;
	q.push(1);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (dist[next].first == dist[here].first + nextcost) {
				if (dist[next].second > dist[here].second + 1) {
					dist[next].second = dist[here].second + 1;
					q.push(next);
				}
			}
			if (dist[next].first > dist[here].first + nextcost) {
				dist[next].first = dist[here].first + nextcost;
				dist[next].second = dist[here].second + 1;
				q.push(next);
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second, ten, one, ti;
		scanf("%d%d%d%d%d", &first, &second, &ten, &one, &ti);
		if (ti > 10) {
			a[first].push_back({ second,ten + one * (ti - 10) });
		}
		else a[first].push_back({ second,ten });
	}
	bfs();
	if (dist[n].first==1e9) {
		printf("It is not a great way.\n");
	}
	else {
		printf("%d %d\n", dist[n].first,dist[n].second);
	}
	return 0;
}