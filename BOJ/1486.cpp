
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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int,int> P;
typedef pair<pair<int, int>,int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int n,m,t,d;
int board[655][655];
char s[25][25];
void floyd() {
	for (int k = 0; k < n*m; k++) {
		for (int i = 0; i < n*m; i++) {
			for (int j = 0; j < n*m; j++) {
				if (board[i][k] != 1e9 && board[k][j] != 1e9) {
					if (board[i][j] > board[i][k] + board[k][j]) {
						board[i][j] = board[i][k] + board[k][j];
					}
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &t,&d);
	for (int i = 0; i <n; i++) {
		for (int j = 0; j <m; j++) {
			scanf(" %c", &s[i][j]);
		}
	}
	for (int i = 0; i <n*m; i++) {
		for (int j = 0; j <n*m; j++) {
			if (i == j) continue; // 갔다가 돌아와야 하는데, [0][0]이 inf이면, 원래는 최단경로는 0인데, 값이 0이상의 값이 주어질수 있기 때문임
			board[i][j] = 1e9;
		}
	}
	for (int i = 0; i <n; i++) {
		for (int j = 0; j <m; j++) {
			char here =s[i][j];
			int first = i*m +j;
			for (int k = 0; k < 4; k++) {
				int nx = i + gox[k];
				int ny = j + goy[k];
				if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
				else {
					char next = s[nx][ny];
					int second = nx*m + ny;
					int temp1 = 0;
					int temp2 = 0;
					if (here >= 'A' && here <= 'Z') {
						temp1 = (here - 'A');
					}
					if (here >= 'a' && here <= 'z') {
						temp1 =(here - 'a' + 26);
					}
					if (next>= 'A' && next <= 'Z') {
						temp2 = (next - 'A');
					}
					if (next >= 'a' && next <= 'z') {
						temp2 = (next - 'a' + 26);
					}
					if (abs(temp1 - temp2) > t) continue; // 문제오해
					if (temp1 >= temp2) {
						board[first][second] = 1;
					}
					else {
						board[first][second] = (temp1 - temp2)*(temp1 - temp2);
					}
				}
			}
		}
	}

	floyd();
	char Max = 0;
	for (int i = 0; i <n * m; i++) {
		if (board[0][i] == 1e9 || board[i][0] == 1e9) continue;
		if (board[0][i] + board[i][0] <= d) {
			int x = i / m;
			int y = i % m;
			Max = max(Max, s[x][y]);
		}
	}
	if (Max >= 'A' && Max <= 'Z') printf("%d\n", Max - 'A');
	else if (Max >= 'a' && Max <= 'z') printf("%d\n", Max - 'a' + 26);
	return 0;
}