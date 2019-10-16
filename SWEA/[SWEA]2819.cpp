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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int n;
int board[5][5];
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int ans = INT_MAX;
vector<int> v, temp;
map<string, int> m;
bool visited[25];
void dfs(int x, int y, int cnt, int depth, string temp) {
	if (cnt == depth) {
		if (m.count(temp) == 0) {
			m[temp] = 1;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >=4) continue;
		temp.push_back(board[nx][ny] + '0');
		dfs(nx, ny, cnt + 1, depth, temp);
		temp.pop_back();
	}
}
int main() {
	int t;
	scanf("%d", &t);
	int Case = 1;
	while (t--) {
		m.clear();
		v.clear();
		temp.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf(" %1d", &board[i][j]);
			}
		}
		string temp;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp.push_back(board[i][j] + '0');
				dfs(i, j, 1,7, temp);
				temp.pop_back();
			}
		}
		printf("#%d %d\n",Case++, m.size());
	}
	return 0;
}