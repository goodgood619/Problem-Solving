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
struct P{
	int x,y;
};
int board[105][105];
bool compare(const P &a,const P &b) {
	if (a.y != b.y) return a.y < b.y;
	if (a.x != b.x) return a.x < b.x;
}
int r, c, k;
int check() {
	int Max = 0;
	for (int i = 1; i <= 103; i++) {
		for (int j = 1; j <= 103; j++) {
			if (board[i][j] != 0) {
				Max++;
				break;
			}
		}
	}
	return Max;
}
int check2() {
	int Max = 0;
	for (int j = 1; j <= 103; j++) {
		for (int i = 1; i <= 103; i++) {
			if (board[i][j] != 0) {
				Max++;
				break;
			}
		}
	}
	return Max;
}
int go() {
	int ti = 0,no=0;
	while (1) {
		int Copy[105][105] = { 0, };
		if (board[r][c] == k) {
			break;
		}
		if (ti > 100) {
			no = 1;
			break;
		}
		int garo = check();
		int sero = check2();

		if (garo >= sero) { //가로연산
			for (int i = 1; i <= 103; i++) {
				vector<P> v;
				map<int, int> mm;
				for (int j = 1; j <= 103; j++) {
					mm[board[i][j]]++;
				}
				mm.erase(0);
				if (mm.size() == 0) continue;
				map<int, int>::iterator it;
				for (it = mm.begin(); it != mm.end(); it++) {
					v.push_back({ it->first,it->second });
				}
				sort(v.begin(), v.end(), compare);
				int ptr = 1;
				for (int k = 0; k < v.size(); k++) {
					Copy[i][ptr++] = v[k].x, Copy[i][ptr++] = v[k].y;
				}
			}
			memset(board, 0, sizeof(board));
			for (int i = 1; i <= 103; i++) {
				for (int j = 1; j <= 103; j++) {
					board[i][j] = Copy[i][j];
				}
			}
		}
		else {// 세로연산
			for (int j = 1; j <= 103; j++) {
				vector<P> v;
				map<int, int> mm;
				for (int i = 1; i <= 103; i++) {
					mm[board[i][j]]++;
				}
				mm.erase(0);
				if (mm.size() == 0) continue;
				map<int, int>::iterator it;
				for (it = mm.begin(); it != mm.end(); it++) {
					v.push_back({ it->first,it->second });
				}
				sort(v.begin(), v.end(), compare);
				int ptr = 1;
				for (int k = 0; k < v.size(); k++) {
					Copy[ptr++][j] = v[k].x, Copy[ptr++][j] = v[k].y;
				}
			}
			memset(board, 0, sizeof(board));
			for (int j = 1; j <= 103; j++) {
				for (int i = 1; i <= 103; i++) {
					board[i][j] = Copy[i][j];
				}
			}
		}
		ti++;
	}
	if (no) return -1;
	else return ti;
}
int main() {
	scanf("%d%d%d", &r, &c, &k);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	printf("%d\n", go());
	return 0;
}