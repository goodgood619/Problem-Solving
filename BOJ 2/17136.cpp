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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,ans=1e9;
int board[11][11];
bool visited[11][11];
int a[6] = { 0,5,5,5,5,5 };
void make(int index,int length) {
	int x = index / 10, y = index % 10;
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			board[i][j] = 0;
		}
	}
}
void back(int index,int length) {
	int x = index / 10, y = index % 10;
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			board[i][j] = 1;
		}
	}
}
bool check(int index,int length) {
	int x = index / 10, y = index % 10;
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			if (board[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}
void dfs(int index,int cnt) {
	while (index < 100 && board[index / 10][index % 10] == 0) index++;
	if (index >= 100) {
		int rest = 25 - (a[1]+a[2]+a[3]+a[4]+a[5]);
		ans = min(ans,rest);
		return;
	}

	for (int i = 1; i <= 5; i++) {
		if (check(index, i)) continue;
		if (a[i] > 0) {
			a[i] -= 1;
			make(index,i);
			dfs(index + 1, cnt + 1);
			back(index,i);
			a[i] += 1;
		}
	}
}
int main() {
	setbuf(stdout, NULL);
	int zero = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 0) zero++;
		}
	}
	if (zero == 100) {
		printf("0\n");
		return 0;
	}
	dfs(0,0);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}