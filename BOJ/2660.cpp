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
int gox[4] = { 0, 0,1,-1 };
int goy[4] = { 0, 1,1,1 };
int n;
int board[51][51];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) board[i][j] = 1e9;
		}
	}
	while (1) {
		int first, second;
		scanf("%d%d", &first, &second);
		if (first == -1 && second == -1) break;
		board[first][second] = 1;
		board[second][first] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] > board[i][k] + board[k][j]) {
					board[i][j] = board[i][k] + board[k][j];
				}
			}
		}
	}
	int ans = 1e9;
	int num[51] = { 0, };
	for (int i = 1; i <= n; i++) {
		int Max = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				Max = max(Max, board[i][j]);
				num[i] = max(Max,num[i]);
			}
		}
		ans = min(ans, Max);
	}
	int cnt = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (num[i] == ans) v.push_back(i);
	}
	printf("%d %d\n", ans,v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}