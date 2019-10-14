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
int check(int **tempboard,int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tempboard[i][j] == 1) return 1;
		}
	}
	return 0;
}
void movedown(int **tempboard,int n,int m) {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if(i!=n-1) tempboard[i + 1][j] = tempboard[i][j];
		}
	}
	for (int j = 0; j < m; j++) tempboard[0][j] = 0;
}
bool compare(const position &a,const position &b) {
	if (a.dist != b.dist) return a.dist < b.dist;
	if (a.y != b.y) return a.y < b.y;
}
int go2(int **board,int n,int m,int d) {
	int** tempboard = new int*[n + 1];
	for (int i = 0; i <= n; i++) tempboard[i] = new int[m];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			tempboard[i][j] = board[i][j];
		}
	}
	int attacked = 0;
	while (true) {
		vector<position> shooted;
		for (int j = 0; j < m; j++) {
			if (tempboard[n][j] == 2) {
				vector<position> v;
				for (int k = 0; k < n; k++) {
					for (int p = 0; p < m; p++) {
						if (tempboard[k][p] == 1 && abs(n-k)+abs(j-p)<=d) {
							v.push_back({ k,p,abs(n - k) + abs(j - p) });
						}
					}
				}
				sort(v.begin(), v.end(), compare);
				if(v.size()>=1)shooted.push_back(v[0]);
			}
		}

		for (int i = 0; i < shooted.size(); i++) {
			int x = shooted[i].x, y = shooted[i].y;
			if (tempboard[x][y] == 1) {
				tempboard[x][y] = 0;
				attacked++;
			}
		}
		movedown(tempboard,n,m);
		if (!check(tempboard, n, m)) break;

	}
	return attacked;
}
void go(int here,int cnt,int depth,int **board,int *visited,int n,int m,int &ans,int d) {
	if (cnt==depth) {
		ans= max(ans,go2(board,n,m,d));
		return;
	}
	for (int i = here; i < m; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			board[n][i] = 2; //궁수
			go(i + 1, cnt + 1, depth, board, visited,n, m,ans,d);
			board[n][i] = 0;
			visited[i] = 0;
		}
	}
}
int main() {
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	int** board = new int*[n + 1];
	int* visited = new int[m];
	for (int i = 0; i <= n; i++) board[i] = new int[m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int i = 0; i < m; i++) visited[i] = 0;
	for (int j = 0; j < m; j++) board[n][j] = 0;
	int ans = 0;
	go(0, 0, 3, board, visited,n,m,ans,d);
	printf("%d\n", ans);
	return 0;
}