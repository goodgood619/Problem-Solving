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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
char board[1003][1003];
bool visited[1003][1003];
map<pair<int, int>, int > m;
set<pair<int, int>> s;
pair<int, int> bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int area = 1, perimeter = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx <= 0 || nx >= n + 1 || ny <= 0 || ny >= n + 1 || board[nx][ny]=='.') {
				perimeter++;
				continue;
			}
			if (visited[nx][ny]) continue;
			if (!visited[nx][ny] && board[nx][ny] == '#') {
				area++;
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	return { area,perimeter };
}
bool compare(const pair<int,int> &a,const pair<int,int> &b) {
	if (a.first != b.first) return a.first > b.first;
	if (a.second != b.second) return a.second < b.second;
	return a.second < b.second;
}
int main() {
	setbuf(stdout, NULL);
	scanf(" %d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && board[i][j] == '#') {
				pair<int,int> a=bfs(i, j);
				s.insert({ a.first, a.second});
			}
		}
	}
	set<pair<int, int>>::iterator it;
	for (it = s.begin(); it != s.end(); it++) v.push_back({ it->first,it->second });
	sort(v.begin(), v.end(), compare);
	printf("%d %d\n", v[0].first, v[0].second);
	return 0;
}