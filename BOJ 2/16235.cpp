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
int gox[8] = {0,-1,0,1,1,1,-1,-1 };
int goy[8] = { 1,0,-1,0,-1,1,1,-1 };
struct position {
	int x;
	int y;
	int age;
};
void spring(vector<vector<vector<int>>> &v,int **board, vector<vector<vector<int>>> &Die,int &n) {
	vector<vector<vector<int>>> live;
	live.assign(n, vector<vector<int>>(n, vector<int>(0, 0)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].size() == 0) continue;
			sort(v[i][j].begin(), v[i][j].end());
			for (int k = 0; k < v[i][j].size(); k++) {
				int age = v[i][j][k];
				if (age <= board[i][j]) {
					board[i][j] -= age;
					live[i][j].push_back(age + 1);
				}
				else {
					Die[i][j].push_back(age);
				}
			}
		}
	}
	//v.clear(); //단순대입을 해도 됨(값이 그대로 복사됨,생각해보니 어차피 n,n공간이 같네)
	v = live;
}
void summer(int **board,vector<vector<vector<int>>> &Die,int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < Die[i][j].size(); k++) {
				board[i][j] += (Die[i][j][k] / 2);
			}
		}
	}

}
void fall(vector<vector<vector<int>>> &v, int **board,int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < v[i][j].size(); k++) {
				int age = v[i][j][k];
				if (age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int nx = i + gox[k], ny = j + goy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						v[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}
void winter(int **board,int **earnboard,int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] += earnboard[i][j];
		}
	}
}
void go(vector<vector<vector<int>>> &v,int k,int &n,int **board,int **earnboard) {
	for (int i = 1; i <= k; i++) {
		vector<vector<vector<int>>> Die;
		Die.assign(n, vector<vector<int>>(n, vector<int>(0, 0)));
		spring(v,board,Die,n);
		summer(board,Die,n);
		fall(v,board,n);
		winter(board,earnboard,n);
	}

}
int main() {
	int n, m, k;
	scanf(" %d%d%d", &n, &m,&k);
	int** earnboard = new int*[n];
	int** board = new int* [n];
	for (int i = 0; i < n; i++) {
		earnboard[i] = new int[n];
		board[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &earnboard[i][j]);
			board[i][j] = 5;
		}
	}
	vector<vector<vector<int>>> v;
	v.assign(n, vector<vector<int>>(n,vector<int>(0,0)));
	for (int i = 0; i < m; i++) {
		int x, y, age;
		scanf(" %d%d%d", &x, &y, &age);
		x--, y--;
		v[x][y].push_back(age);
	}
	go(v, k, n,board, earnboard);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += v[i][j].size();
		}
	}
	printf("%d\n",ans);
	for (int i = 0; i < n; i++) {
		delete[] earnboard[i];
		delete[] board[i];
	}
	delete[] earnboard;
	delete[] board;
	return 0;
}