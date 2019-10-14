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
int check(int here,int length,int **board) {
	int x = here / 10,y = here % 10;
	if (x + length >= 10 || y + length >= 10) return 1;
	for (int i = x; i <= x + length; i++) {
		for (int j = y; j <= y + length; j++) {
			if (board[i][j] == 0) return 1;
		}
	}
	return 0;
}
void make(int here,int **board,int length) {
	int x = here / 10, y = here % 10;
	for (int i = x; i <= x + length; i++) {
		for (int j = y; j <= y + length; j++) {
			board[i][j] = 0;
		}
	}
}
void back(int here,int **board,int length) {
	int x = here / 10, y = here % 10;
	for (int i = x; i <= x + length; i++) {
		for (int j = y; j <= y + length; j++) {
			board[i][j] = 1;
		}
	}
}
void go(int here,int **board,int &ans,int *paper) {
	while (here < 100 && board[here / 10][here % 10] == 0) here++;
	if (here >= 100) {
		ans = min(ans, 25 - paper[0] - paper[1] - paper[2] - paper[3] - paper[4]);
		return;
	}
	for (int i = 5; i >= 1; i--) {
		if (check(here, i-1,board) == 1) continue;
		if (paper[i - 1] > 0) {
			paper[i - 1] -= 1;
			make(here,board,i-1);
			go(here + 1, board, ans, paper);
			back(here,board,i-1);
			paper[i - 1] += 1;
		}
	}
}
int main() {
	int** board = new int*[10];
	int* paper = new int[5];
	for (int i = 0; i < 5; i++) paper[i] = 5;
	for (int i = 0; i < 10; i++) board[i] = new int[10];
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	int ans = 1e9;
	go(0,board,ans,paper);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}