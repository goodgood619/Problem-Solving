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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n, m;
char board[100][100];
bool visited[15];
map<int, int> check;
int make(int x, int y) {
	for (int i = 1;; i++) {
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int nx = x + i*gox[k];
			int ny = y + i * goy[k];
			if (nx<0 || nx>=n || ny<0 || ny>=m || board[nx][ny] == '.') continue;
			cnt++;
		}
		if (cnt != 4) return i - 1;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	int star = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == '*') star++;
		}
	}
	vector<PP> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '.') continue;
			int length = make(i, j);
			if (length == 0) continue;
			else {
				check[i*m + j]++; //센터값 더하기
				for (int p = 1; p <= length; p++) {
					for (int k = 0; k < 4; k++) {
						int nx = i + p * gox[k];
						int ny = j + p * goy[k];
						check[nx*m + ny]++;
					}
				}
				ans.push_back({ {i,j },length });
			}
		}
	}

	if (check.size() < star) {
		printf("-1\n");
	}
	else if (check.size() == star) {
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d %d %d\n", ans[i].first.first+1, ans[i].first.second+1, ans[i].second);
		}
	}
	return 0;
}