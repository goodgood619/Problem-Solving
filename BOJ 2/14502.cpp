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
};
int bfs(int**board,vector<position> &temp,int n,int m) {
	queue<position> q;
	int** tempboard = new int*[n + 1];
	int** tempvisited = new int* [n + 1];
	for (int i = 1; i <= n; i++) {
		tempboard[i] = new int[m + 1];
		tempvisited[i] = new int[m + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tempboard[i][j] = board[i][j];
			tempvisited[i][j] = 0;
			if (board[i][j] == 2) {
				q.push({ i,j });
				tempvisited[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < temp.size(); i++) {
		tempboard[temp[i].x][temp[i].y] = 1;
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i], ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || tempvisited[nx][ny] || tempboard[nx][ny] == 1 || tempboard[nx][ny] == 2) continue;
			else if (!tempvisited[nx][ny] && tempboard[nx][ny] == 0) {
				tempboard[nx][ny] = 2;
				q.push({ nx,ny });
				tempvisited[nx][ny] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (tempboard[i][j] == 0) ans++;
		}
	}
    for(int i=1;i<=n;i++){ 
        delete[] tempboard[i];
        delete[] tempvisited[i];
    }
    delete[] tempboard;
    delete[] tempvisited;
	return ans;
}
void go(int here,int cnt,int depth,int **board,int *visited,vector<position> &v,vector<position> &temp,int n,int m,int &ans) {
	if (cnt == depth) {
		ans=max(ans,bfs(board,temp,n,m));
		return;
	}
	for (int i = here; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = 1;
			temp.push_back(v[i]);
			go(i + 1, cnt + 1, depth, board, visited, v, temp,n,m,ans);
			temp.pop_back();
			visited[i] = 0;
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int** board = new int* [n + 1];
	int area = (n + 1) * (m + 1);
	int* visited = new int[area + 1];
	for (int i = 0; i <n * m; i++) visited[i] = 0;
	vector<position> v,temp;
	for (int i = 1; i <= n; i++) {
		board[i] = new int[m + 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	int ans = 0;
	go(0, 0, 3,board,visited,v,temp,n,m,ans);
	printf("%d\n", ans);
    for(int i=1;i<=n;i++) delete[] board[i];
    delete[] board;
    delete[] visited;
	return 0;
}