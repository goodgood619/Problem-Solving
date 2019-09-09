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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[55][55];
int n, m, s;
vector<int> v;
void floyd() {
	for (int k = 1; k <= 52; k++) {
		for (int i = 1; i <= 52; i++) {
			for (int j = 1; j <= 52; j++) {
				if (board[i][k] && board[k][j]) {
					board[i][j]=1;
				}
			}
		}
	}
}
int main() {
	scanf(" %d", &n);
	for (int i = 1; i <= n; i++) {
		char s[35] = { '\0', };
		scanf(" %[^\n]s", s);
		int length = strlen(s);
		if (s[0] >= 'A' && s[0] <= 'Z') {
			s[0] -= 64;
		}
		if (s[length - 1] >= 'A' && s[length - 1] <= 'Z') {
			s[length-1] -= 64;
		}
		if (s[0] >= 'a' && s[0] <= 'z') {
			s[0] -= 70;
		}
		if (s[length - 1] >= 'a' && s[length - 1] <= 'z') {
			s[length - 1] -= 70;
		}
		board[(int)s[0]][(int)s[length - 1]] = 1;
	}
	floyd();
	int cnt = 0;
	for (int i = 1; i <= 52; i++) {
		for (int j = 1; j <= 52; j++) {
			if (i == j) continue;
			if (board[i][j]) cnt++;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= 52; i++) {
		for (int j = 1; j <= 52; j++) {
			if (i == j) continue;
			if (board[i][j]) {
				if(i<=26 && j<=26) printf("%c => %c\n", i + 64, j + 64);
				else if (i <= 26 && j >= 27) printf("%c => %c\n", i + 64, j + 70);
				else if (i >= 27 && j <= 26) printf("%c => %c\n", i + 70, j + 64);
				else printf("%c => %c\n", i + 70, j + 70);
			}
		}
	}
	return 0;
}
