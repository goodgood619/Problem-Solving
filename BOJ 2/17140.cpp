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
struct pos {
	int num;
	int numcnt;
};
int check1(int **board) {
	int temp = 0;
	for (int i = 1; i <= 100; i++) {
		int tempcow = 0;
		for (int j = 1; j <= 100; j++) {
			if (board[i][j] == 0) {
				break;
			}
			else tempcow++;
		}
		temp = max(temp, tempcow);
	}
	return temp;
}
int check2(int **board) {
	int temp = 0;
	for (int j = 1; j <= 100; j++) {
		int tempcow = 0;
		for (int i = 1; i <= 100; i++) {
			if (board[i][j] == 0) {
				break;
			}
			else tempcow++;
		}
		temp = max(temp, tempcow);
	}
	return temp;
}
bool compare(const pos &a,const pos &b) {
	if (a.numcnt != b.numcnt) return a.numcnt < b.numcnt;
	if (a.num != b.num) return a.num < b.num;
}
void go(int **board,int &Time,int r,int c,int k) {
	while (true) {
		if (Time > 100 || board[r][c] ==k) break;
		int rowcnt = 0, cowcnt = 0;
		cowcnt = check1(board);
		rowcnt = check2(board);
		int **tempboard = new int*[101];
		for (int i = 1; i <= 100; i++) tempboard[i] = new int[101];
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				tempboard[i][j] = 0;
			}
		}
		if (rowcnt >= cowcnt) { //R연산,모든 행에대하여 정렬수행
			for (int i = 1; i <= 100; i++) {
				map<int, int> cnt;
				vector<pos> v;
				for (int j = 1; j <= 100; j++) {
					if(board[i][j]!=0) cnt[board[i][j]]++;
				}
				map<int, int>::iterator it;
				for (it = cnt.begin(); it != cnt.end(); it++) {
					v.push_back({ it->first,it->second });
				}
				sort(v.begin(), v.end(), compare);
				int idx = 1;
				for (int k = 0; k < v.size(); k++) {
					int here = v[k].num, next = v[k].numcnt;
					tempboard[i][idx++] = here;
					tempboard[i][idx++] = next;
					if (idx > 100) break;
				}
			}

		}
		else { //C연산, 모든 열에 대하여 정렬 수행
			for (int j = 1; j <= 100; j++) {
				map<int, int> cnt;
				vector<pos> v;
				for (int i = 1; i <= 100; i++) {
					if (board[i][j] != 0) cnt[board[i][j]]++;
				}
				map<int, int>::iterator it;
				for (it = cnt.begin(); it != cnt.end(); it++) {
					v.push_back({ it->first,it->second });
				}
				sort(v.begin(), v.end(), compare);
				int idx = 1;
				for (int k = 0; k < v.size(); k++) {
					int here = v[k].num, next = v[k].numcnt;
					tempboard[idx++][j] = here;
					tempboard[idx++][j] = next;
					if (idx > 100) break;
				}
			}
		}
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				board[i][j] = tempboard[i][j];
			}
		}
        for(int i=1;i<=100;i++) delete[] tempboard[i];
        delete[] tempboard;
		Time++;
	}
}
int main() {
	int r, c, k,Time=0;
	scanf("%d%d%d", &r, &c, &k);
	int **board = new int*[101];
	for (int i = 1; i <= 100; i++) board[i] = new int[101];
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			board[i][j] = 0;
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	go(board, Time,r,c,k);
	Time > 100 ? printf("-1\n") : printf("%d\n", Time);
    for(int i=1;i<=100;i++) delete[] board[i];
    delete[] board;
	return 0;
}