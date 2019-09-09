
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
typedef pair<int, pair<ll, char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
char board[4][4];
char board2[4][4];
int main() {
	char start = 'A';
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 3 && j == 3) {
				board[i][j] = '.';
				continue;
			}
			board[i][j] = start++;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf(" %c", &board2[i][j]);
		}
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char here = board[i][j];
			int cnt = 0;
			bool check = false;
			for (int k = 0; k < 4; k++) {
				for (int p = 0; p < 4; p++) {
					if (here == board2[k][p] && board2[k][p]!='.') {
						cnt = abs(i - k) + abs(j - p);
						check = true;
						break;
					}
				}
				if (check) break;
			}
			sum += cnt;
		}
	}
	printf("%d\n", sum);
	return 0;
}