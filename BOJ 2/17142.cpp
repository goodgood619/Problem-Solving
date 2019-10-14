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
struct position {
	int x;
	int y;
};
struct pos {
	int x;
	int y;
	int dist;
};
int bfs(int **board,int *visited,vector<position> &v,int n) {
	queue<pos> q;
	int MaxTime = 0;
	int **tempvisited = new int*[n];
	for (int i = 0; i < n; i++) tempvisited[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tempvisited[i][j] = 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (visited[i]) {
			q.push({ v[i].x,v[i].y,0 });
			tempvisited[v[i].x][v[i].y] = 1;
		}
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i], ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || tempvisited[nx][ny] || board[nx][ny] == 1) continue;
			else if (!tempvisited[nx][ny]) {
					tempvisited[nx][ny] = 1;
				if (board[nx][ny] == 2) {
					q.push({ nx,ny,dist+1 });
				}
				else {
					q.push({ nx,ny,dist + 1 });
					MaxTime = max(MaxTime, dist+1);
				}
			}
		}
	}
	int no = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) continue;
			else {
				if (tempvisited[i][j] == 0) {
					no = 1;
					break;
				}
			}
		}
		if (no) break;
	}
    for(int i = 0;i<n;i++) delete[] tempvisited[i];
    delete[] tempvisited;
	if (no) return 1e9;
	else return MaxTime;
}
void go(int here,int cnt,int depth,int **board,int *visited,vector<position> &v,int &ans,int n) {
	if (cnt == depth) {
		ans = min(ans, bfs(board,visited,v,n));
		return;
	}

	for (int i = here; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = 1;
			go(i + 1, cnt + 1, depth, board, visited, v, ans,n);
			visited[i] = 0;
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<position> v;
	int **board = new int*[n];
	int *visited = new int[10];
	for (int i = 0; i < 10; i++) visited[i] = 0;
	for (int i = 0; i < n; i++) board[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
	int ans = 1e9;
	go(0, 0, m, board, visited, v,ans,n);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
    delete[] visited;
    for(int i=0;i<n;i++) delete[] board[i];
    delete[] board;
	return 0;
}