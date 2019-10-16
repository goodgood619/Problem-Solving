

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
#include <time.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<ll, pair<ll, ll>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,0,-1 };
int goy[4] = { 1,0,-1,0 };
bool ok;
vector<vector<int>> board;
vector<P> v;
int t, cnt, n;
int ans = 1e9;
int check(int x, int y, int dir) {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		int nx = x + i*gox[dir];
		int ny = y + i*goy[dir];
		if (nx == 0 || nx == n - 1 || ny == 0 || ny == n - 1) {
			if (board[nx][ny] == 1 || board[nx][ny] == -1) return 0; // 선이나 코어가 되어 있다면 연결불가
			c++; // 빈곳이면 갯수한개더증가
			break;
		}
		else {
			if (board[nx][ny] == -1 || board[nx][ny] == 1) return 0;
			c++;
		}
	}
	return c;
}
void make(int x, int y, int dir, int length) {
	for (int i = 1; i <= length; i++) {
		int nx = x + i*gox[dir];
		int ny = y + i*goy[dir];
		board[nx][ny] = -1;
	}
	return;
}
void nomake(int x, int y, int dir, int length) {
	for (int i = 1; i <= length; i++) {
		int nx = x + i*gox[dir];
		int ny = y + i*goy[dir];
		board[nx][ny] = 0;
	}
	return;
}
void go(int index, int CNT, int total) {
	if (index == v.size()) {
		if (cnt < CNT) {
			cnt = CNT;
			ans = total;
		}
		else if (cnt == CNT) {
			ans = min(ans, total);
		}
		return;
	}
	int x = v[index].first;
	int y = v[index].second;
	for (int k = 0; k < 4; k++) {
		int length = check(x, y, k);
		if (length == 0) continue; // 연결불가
		else {
			make(x, y, k,length);
			go(index + 1, CNT + 1,total + length);
			nomake(x, y, k, length);
		}
	}
	go(index + 1, CNT,total);
}
int main() {
	scanf("%d", &t);
	int Case = 1;
	while (t--) {
		ans = 1e9;
		scanf("%d", &n);
		board.clear();
		v.clear();
		cnt = 0;
		board.resize(n + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int num;
				scanf(" %1d", &num);
				board[i].push_back(num);
				if (i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
				if (board[i][j] == 1) v.push_back({ i,j });
			}
		}
		go(0, 0,0);
		printf("#%d %d\n", Case, ans);
		Case++;
	}
	return 0;
}
