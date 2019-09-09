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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n, m,total,Max;
bool visited[200005];
char board[51][51];
vector<vector<pair<int, int>>> a;
void prim(int st) {
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (visited[here]) continue;
		visited[here] = true;
		total += cost;
		Max = max(Max, cost);
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (!visited[next]) pq.push({ nextcost,next });
		}
	}
}
int bfs(int sx,int sy,int ex,int ey) {
	queue<PPP> q;
	q.push({ 0,{sx,sy} });
	bool visited2[51][51] = { false, };
	visited2[sx][sy] = true;
	while (!q.empty()) {
		int dist = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (ex == x && ey == y) return dist;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>n || board[nx][ny] == '1' || visited2[nx][ny]) continue;
			if (!visited2[nx][ny]) {
				visited2[nx][ny] = true;
				q.push({ dist + 1,{nx,ny} });
			}	
		}
	}
	return 1e9;
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(m + 1);
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'S' || board[i][j] == 'K') {
				v.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int dist = bfs(v[i].first, v[i].second, v[j].first, v[j].second);
			if (dist == 1e9) {
				printf("-1\n");
				return 0;
			}
			a[i].push_back({ j,dist });
			a[j].push_back({ i,dist });
		}
	}
	prim(0);
	printf("%d\n", total);
	return 0;
}