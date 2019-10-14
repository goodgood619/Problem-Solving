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
void dfs(int x,int y,int **visited,int **board,int &n,int &l,int &r,vector<position> &nation) {
	visited[x][y] = 1;
	nation.push_back({ x,y });
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i], ny = y + goy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || abs(board[x][y] - board[nx][ny]) < l || abs(board[x][y] - board[nx][ny]) > r) continue;
		else {
			dfs(nx, ny, visited, board, n, l, r,nation);
		}
	}
}
void reset(int **visited,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}
int main() {
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	int** board = new int* [n];
	int** visited = new int* [n];
	for (int i = 0; i < n; i++) { 
		board[i] = new int[n]; 
		visited[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
			visited[i][j] = 0;
		}
	}
	int cnt = 0;
	while (true) {
		int change = 0;
		int area = 0;
		vector<vector<position>> Union;
		reset(visited,n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					vector<position> nation;
					dfs(i, j, visited, board,n,l,r,nation);
					area++;
					Union.push_back(nation);
				}
			}
		}
		if (area == n * n) break; //모든 국가가 하나의 연합을 이룰때 끝

		//인구이동
		for (int i = 0; i < Union.size(); i++) {
			int sum = 0;
			for (int j = 0; j < Union[i].size(); j++) {
				int x = Union[i][j].x, y = Union[i][j].y;
				sum += board[x][y];
			}
			sum /= Union[i].size();
			//다시 위치시키기
			for (int j = 0; j < Union[i].size(); j++) {
				int x = Union[i][j].x, y = Union[i][j].y;
				board[x][y] = sum;
			}
		}
		cnt++;

	}
	printf("%d\n", cnt);
	return 0;
}