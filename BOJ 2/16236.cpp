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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
struct position {
	int x;
	int y;
	int dist;
};
void reset(int** visited, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int sharkx,int sharky,int **board,int n,vector<position> &eatok,int sharklevel) {
	int** visited = new int*[n];
	for (int i = 0; i < n; i++) visited[i] = new int[n];
	reset(visited,n);
	visited[sharkx][sharky] = 1;
	queue<position> q;
	q.push({ sharkx,sharky,0 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i], ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || sharklevel < board[nx][ny]) continue;
			else {
				q.push({ nx,ny,dist + 1 });
				visited[nx][ny] = 1;
				if (board[nx][ny] != 0 && sharklevel>board[nx][ny]) {
					eatok.push_back({ nx,ny,dist + 1 });
				}
			}
		}
	}
}
bool compare(const position &a,const position &b) {
	if (a.dist != b.dist) return a.dist < b.dist;
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
}
int main() {
	int n;
	scanf("%d", &n);
	int** board = new int*[n];
	int sharklevel = 2,sharkx = 0,sharky = 0;
	int eat = 0;
	for (int i = 0; i < n; i++) board[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 9) {
				sharkx = i, sharky = j;
			}
		}
	}

	int Time = 0;
	while (true) {
		vector<position> eatok;
		bfs(sharkx, sharky, board,n, eatok,sharklevel);
		if (eatok.size() == 0) break;
		sort(eatok.begin(), eatok.end(), compare);
		int nx = eatok[0].x, ny = eatok[0].y,PlusTime = eatok[0].dist;
		board[nx][ny] = 9;
		board[sharkx][sharky] = 0;
		eat++;
		eatok.clear();
		sharkx = nx, sharky = ny;
		if (eat == sharklevel) {
			eat = 0;
			sharklevel++;
		}
		Time+=PlusTime;
	}
	printf("%d\n", Time);
	return 0;
}