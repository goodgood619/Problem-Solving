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
int bfs(vector<position> &chick,int *visited,int Size,int **board,int n) {
	vector<position> selected;
	for (int i = 0; i < Size; i++) {
		if(visited[i]==1) selected.push_back({ chick[i].x,chick[i].y });
	}
	vector<position> home;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) {
				home.push_back({ i,j });
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < home.size(); i++) {
		int tempdist = 1e9;
		for (int j = 0; j < selected.size(); j++) {
			tempdist = min(tempdist, abs(home[i].x - selected[j].x) + abs(home[i].y - selected[j].y));
		}
		ans += tempdist;
	}

	return ans;
}
void go(int here,int cnt,int depth,vector<position> &chick,int *visited,int Size,int **board,int n,int &ans) {
	if (cnt == depth) {
		ans=min(ans,bfs(chick,visited,Size,board,n));
		return;
	}
	for (int i = here; i < chick.size(); i++) {
		if (!visited[i]) {
			visited[i] = 1;
			go(i + 1, cnt + 1, depth, chick, visited,Size,board,n,ans);
			visited[i] = 0;
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int** board = new int*[n];
	vector<position> chick;
	for (int i = 0; i < n; i++) board[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
			if(board[i][j] == 2) chick.push_back({ i,j });
		}
	}
	int Size = chick.size();
	int ans = 1e9;
	int* visited = new int[Size];
	for (int i = 0; i <Size; i++) visited[i] = 0;
	go(0, 0, m, chick, visited,Size,board,n,ans);
	printf("%d\n", ans);
	return 0;
}