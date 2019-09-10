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
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
vector<ll> v;
int n, m;
int board[27][27];
int main() {
	scanf(" %d", &n);
	for (int i = 1; i <= n; i++) {
		char left, right;
		scanf(" %c is %c", &left, &right);
		board[left - 'a'+1][right - 'a'+1] = 1;
	}

	for (int k = 1; k <= 26; k++) {
		for (int i = 1; i <= 26; i++) {
			for (int j = 1; j <= 26; j++) {
				if (board[i][k] && board[k][j]) board[i][j] = 1;
			}
		}
	}
	scanf(" %d", &m);
	for (int i = 1; i <= m; i++) {
		char left, right;
		scanf(" %c is %c", &left, &right);
		board[left - 'a' + 1][right - 'a' + 1] == 1 ? printf("T\n") : printf("F\n");
	}

	return 0;
}