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
typedef pair<int, int> P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
char board[15][15];
char pan[15][15];
int main() {
	scanf("%d", &n);
	if (n % 2 == 1) {
		printf("invalid grille\n");
		return 0;
	}
	string s;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == '.') cnt++;
		}
	}
	if (cnt != n * n / 4) {
		printf("invalid grille\n");
		return 0;
	}
	cin >> s;
	int ptr = 0;
	bool no = false;
	int length = s.size();
	while (ptr < length) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] == '.') {
					if (pan[i][j] != '.' && pan[i][j] != '\0') {
						no = true;
						break;
					}
					pan[i][j] = s[ptr++];
				}
			}
			if (no) break;
		}
		if (no) {
			printf("invalid grille\n");
			return 0;
		}
		vector<vector<char>> temp(15, vector<char>(15));
		for (int j = 1, px = 1; j <= n; j++, px++) {
			for (int i = n, py = 1; i >= 1; i--, py++) {
				if (board[i][j] == '.') {
					temp[px][py] = '.';
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				board[i][j] = temp[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%c", pan[i][j]);
		}
	}
	return 0;
}