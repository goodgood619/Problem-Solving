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
char board[4000][8000];
int n;
void go(int n,int x,int y) {
	if (n == 3) {
		int cnt = 1;
		for (int i = x; i <= x + 2; i++) {
			int here = 2 * cnt - 1;
			int j = y - cnt + 1;
			while (here--) {
				if (i == x + 1 && j == y) {
					j++;
					continue;
				}
				board[i][j] = '*';
				j++;
			}
			cnt++;
		}
		return;
	}
	go(n / 2, x, y);
	go(n / 2, x + n / 2, y - n / 2);
	go(n / 2, x + n / 2, y + n / 2);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			board[i][j] = ' ';
		}
	}
	go(n,1,n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			printf("%c", board[i][j]);
		}
		if (i == n) continue;
		printf("\n");
	}
	return 0;
}