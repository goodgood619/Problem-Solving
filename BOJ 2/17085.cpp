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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m,ans=1;
vector<int> v;
char board[15][15];
bool visited[15][15];
map<pair<int, int>, vector<int>> check;
int go(int sx1,int sy1,int sx2,int sy2,int cnt1,int cnt2) {
	memset(visited, false, sizeof(visited));
	int p1 = cnt1, p2 = cnt2;
	visited[sx1][sy1] = true, cnt1--;
	for (int i = 1;; i++) {
		if (cnt1 == 0) break;
		for (int j = 0; j < 4; j++) {
			int nx = sx1 + i * gox[j], ny = sy1 + i * goy[j];
			visited[nx][ny] = true, cnt1--;
		}
	}
	if (visited[sx2][sy2]) {
		return 0;
	}
	else {
		visited[sx2][sy2] = true, cnt2--;
		for (int i = 1;; i++) {
			if (cnt2 == 0) break;
			for (int j = 0; j < 4; j++) {
				int nx = sx2 + i * gox[j], ny = sy2 + i * goy[j];
				if (visited[nx][ny]) return 0;
				else {
					visited[nx][ny] = true, cnt2--;
				}
			}
		}
		return p1 * p2;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cx = i, cy = j;
			if (board[cx][cy] == '.') continue;
			else {
				check[{cx, cy}].push_back(1);
				int cnt = 1;
				for (int p = 1; p < max(n, m); p++) {
					int no = 0;
					for (int k = 0; k < 4; k++) {
						int tx = cx + p * gox[k], ty = cy + p * goy[k];
						if (tx < 0 || tx >= n || ty < 0 || ty >= m || board[tx][ty] == '.') {
							no = 1;
							break;
						}
					}
					if (no) break;
					cnt += 4;
					check[{cx, cy}].push_back(cnt);
				}
			}
		}
	}
	int ans = 1;
	map<pair<int, int>, vector<int>>::iterator it,it2;
	for (it = check.begin(); it != check.end(); it++) {
		for (it2 = check.begin(); it2 != check.end(); it2++) {
			if (it->first == it2->first) continue;
			int cx1 = it->first.first, cy1 = it->first.second, cx2 = it2->first.first, cy2 = it2->first.second;
			vector<int> temp1 = it->second;
			vector<int> temp2 = it2->second;
			for (int i = 0; i < temp1.size(); i++) {
				for (int j = 0; j < temp2.size(); j++) {
					ans=max(ans,go(cx1, cy1, cx2, cy2, temp1[i], temp2[j]));
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}