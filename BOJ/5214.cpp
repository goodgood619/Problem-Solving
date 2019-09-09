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
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
vector<vector<int>> hyper; //호선
vector<vector<int>> station; // 역
int n, k, m;
bool visited[100005];
bool routevisited[100005];
int dist[100005];
int bfs(int st) {
	queue<int> q;
	q.push(st);
	dist[st] = 1;
	visited[st] = true;
	for (int i = 0; i < station[st].size(); i++) {
		int next = station[st][i];
		routevisited[next] = true;
		for (int j = 0; j < hyper[next].size(); j++) {
			int state = hyper[next][j];
			if (visited[state]) continue;
			visited[state] = true;
			dist[state] = dist[st]+1;
			q.push(state);
		}
	}

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == n) return dist[n];
		for (int i = 0; i < station[here].size(); i++) {
			int next = station[here][i];
			if (routevisited[next]) continue;
			routevisited[next] = true;
			for (int j = 0; j < hyper[next].size(); j++) {
				if (here == hyper[next][j] || visited[hyper[next][j]]) continue;
				visited[hyper[next][j]] = true;
				q.push(hyper[next][j]);
				dist[hyper[next][j]] = dist[here] + 1;
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d%d%d", &n, &k, &m);
	hyper.resize(m + 1);
	station.resize(n + 1);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int p;
			scanf(" %d", &p);
			hyper[i].push_back(p);
			station[p].push_back(i);
		}
	}

	printf("%d\n",bfs(1));
	return 0;
}