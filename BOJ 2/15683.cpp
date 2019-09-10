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
int t, Case = 1,n,m,ans=1e9;
#define U (1<<0)
#define R (1<<1)
#define D (1<<2)
#define L (1<<3)
vector<int> Move[5] = { {U,R,D,L}, {U | D,R | L},{U | R,U | L,D | R,D | L},{U | R | L,D | R | L,R | U | D,L | U | D},{U | R | D | L} };
int board[9][9];
vector<pair<int, int>> cctvposition;
vector<int> cctv;
int gogo[12];
void dfs(int index) {
	if (index == cctv.size()) {
		int temp[9][9];
		memcpy(temp, board, sizeof(temp));
		for (int i = 0; i < cctvposition.size(); i++) {
			int x = cctvposition[i].first, y = cctvposition[i].second;
			int whatcctv = cctv[i] - 1;
			for (int j = 0; j < 4; j++) {
				if (Move[whatcctv][gogo[i]] & (1 << j)) {
					temp[x][y] = -1;
					for (int k = 1;; k++) {
						int nx = x + k * gox[j], ny=y + k * goy[j];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m || temp[nx][ny] == 6) break;
						temp[nx][ny] = -1;
					}
				}
			}
		}


		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for(int j=0;j<m;j++){
				if (temp[i][j] == 0) cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}

	for (int i = 0; i < Move[cctv[index] - 1].size(); i++) {
		gogo[index] = i;
		dfs(index + 1);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] >= 1 && board[i][j] <= 5) {
				cctv.push_back(board[i][j]);
				cctvposition.push_back({ i,j });
			}
		}
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}