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
int gox[8] = { 0, 0,1,-1,1,1,-1,-1 };
int goy[8] = { -1, 1,0,0,-1,1,1,-1 };
int n, m, k;
int board[12][12];
int Plus[12][12];
int tree[1003][15][15];
vector<PP> die;
void spring() {
	vector<PP> live;
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (tree[i][j][k] == 0) continue;
				int cnt = tree[i][j][k];
				while (board[j][k] >= i && cnt>0) {
					board[j][k] -= i; //나이만큼 양분을 먹음
					cnt--;
					live.push_back({ {j,k }, i + 1 });
				}
				while (cnt > 0) {
					tree[i][j][k]--;
					die.push_back({ { j,k }, i });
					cnt--;
				}
			}
		}
	}

	for (int i = 0; i < live.size(); i++) {
		int x = live[i].first.first, y = live[i].first.second, age = live[i].second;
		tree[age][x][y]++;
		tree[age - 1][x][y]--;
	}
}
void summer() {
	for (int i = 0; i < die.size(); i++) {
		int x = die[i].first.first, y = die[i].first.second, age = die[i].second;
		board[x][y] += (age / 2);
	}
	die.clear();
}
void fall() {
	for (int i = 5; i <= 1000; i += 5) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				int cnt = tree[i][j][k];
				if (cnt == 0) continue;
				else {
					for (int p = 0; p < 8; p++) {
						int nx = j + gox[p];
						int ny = k + goy[p];
						if (nx<1 || nx>n || ny<1 || ny>n) continue;
						else {
							tree[1][nx][ny] += cnt;
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			board[i][j] += Plus[i][j];
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			board[i][j] = 5; //초기 배분 6
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &Plus[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		int x, y, age;
		scanf("%d%d%d", &x, &y, &age);
		tree[age][x][y]++;
	}
	for (int i = 1; i <= k; i++) {
		spring();
		summer();
		fall();
		winter();
	}
	int ans = 0;
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				ans += tree[i][j][k];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}