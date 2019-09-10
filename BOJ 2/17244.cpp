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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,m;
typedef unsigned long long lll;
char board[51][51] = { '\0', };
int bfs(int sx,int sy,int ex,int ey) {
	queue<PPP> q;
	q.push({ 0,{sx,sy} });
	bool visited[51][51] = { false, };
	visited[sx][sy] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (x == ex && y == ey) return cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == '#') continue;
			else {
				visited[nx][ny] = true, q.push({ cnt + 1,{nx,ny} });
			}
		}
	}
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d", &n, &m);
	vector<pair<int, pair<int, int>>> v;
	int idx = 1,st=0,en=0;
	swap(n, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'S' || board[i][j] == 'E' || board[i][j] == 'X') {
				v.push_back({ idx,{i,j} });
				if (board[i][j] == 'S') st = idx;
				else if (board[i][j] == 'E') en = idx;
				idx++;
			}
		}
	}
	int dist[10][10] = { 0, };
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			int here = v[i].first, next = v[j].first;
			dist[here][next] = bfs(v[i].second.first, v[i].second.second, v[j].second.first, v[j].second.second);
		}
	}
	idx--;
	int Min = 1e9;
	vector<int> temp;
	for (int i = 1; i <= idx; i++) {
		if (st == i || en == i) continue;
		temp.push_back(i);
	}
	do {
		if (temp.size() == 0) break;
		int Time = dist[st][temp[0]];
		for (int i = 0; i < temp.size()-1; i++) {
			Time += dist[temp[i]][temp[i + 1]];
		}
		Time += dist[temp[temp.size() - 1]][en];
		Min = min(Min, Time);
	} while (next_permutation(temp.begin(), temp.end()));
	if (Min == 1e9) Min = dist[1][2];
	printf("%d\n", Min);
	return 0;
}