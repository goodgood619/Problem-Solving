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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,sx,sy;
int board[20][20];
vector<pair<pair<int, int>, int>> v;
void bfs(int level) {
	queue<pair<pair<int, int>, int>> q;
	bool visited[20][20] = { false, };
	q.push({ { sx,sy }, 0 });
	visited[sx][sy] = true;
	v.clear();
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i], ny = y + goy[i];
			if (nx < 0 || nx >= n || ny <0 || ny >= n || visited[nx][ny] || level < board[nx][ny]) continue;
			else if (!visited[nx][ny] && level >= board[nx][ny]) {
				q.push({ { nx,ny }, time + 1 });
				visited[nx][ny] = true;
				if (level > board[nx][ny] && board[nx][ny]>0) v.push_back({ { nx,ny }, time + 1 });
			}
		}
	}
}
bool compare(const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b) {
	if (a.second != b.second) return a.second < b.second;
	if (a.first.first != b.first.first) return a.first.first < b.first.first;
	if (a.first.second != b.first.second) return a.first.second < b.first.second;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 9) sx = i, sy = j;
		}
	}

	int level = 2;
	int eat = 0;
	int ans = 0;
	while (true) {
		bfs(level);
		if (v.size() == 0) break;
		sort(v.begin(), v.end(), compare);
		ans += v[0].second;
		eat++;
		if (level == eat) { level++, eat = 0; }
		board[sx][sy] = 0;
		sx = v[0].first.first, sy = v[0].first.second;
		board[sx][sy] = 9;
	}
	printf("%d\n", ans);
	return 0;
}