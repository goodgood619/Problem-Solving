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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[130][130];
int cnt[3];
int n;
void go(int n,int x,int y) {
	if (n == 1) {
		if (board[x][y] == 0) cnt[1]++;
		else cnt[2]++;
		return;
	}
	int temp[3] = { 0, };
	for (int i = x; i < x+n; i++) {
		for (int j = y; j <y+n; j++) {
			if (board[i][j] == 0) temp[1]++;
			else temp[2]++;
		}
	}
	if (temp[1] == n * n) {
		cnt[1]++;
		return;
	}
	if (temp[2] == n * n) {
		cnt[2]++;
		return;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			go(n / 2, x + i * (n / 2), y + j * (n / 2));
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	go(n,1,1);
	for (int i = 1; i < 3; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}