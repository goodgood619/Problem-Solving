#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <deque>
using namespace std;
int gox[8] = { -1,-1,0,1,1,1,0,-1 };
int goy[8] = { 0,1,1,1,0,-1,-1,-1 };
struct res {
	int m,s,d;
};
pair<int,int> move(int x, int y, int d, int s,int n) {
	for (int i = 0; i < s; i++) {
		int nx = x + gox[d];
		int ny = y + goy[d];
		if (nx < 0) {
			nx += n;
		}
		if (nx >= n) {
			nx -= n;
		}
		if (ny < 0) {
			ny += n;
		}
		if (ny >= n) {
			ny -= n;
		}
		x = nx;
		y = ny;
	}
	return { x,y };
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	
	map<pair<int, int>, vector<res>> map;
	vector<vector<vector<res>>> board;
	board.assign(n, vector<vector<res>>(n, vector<res>()));
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		scanf("%d%d%d%d%d", &r, &c, &m, &s, &d);
		r--;
		c--;
		board[r][c].push_back({ m,s,d });
	}
	for (int i = 0; i < k; i++) {
		vector<vector<vector<res>>> tempboard;
		tempboard.assign(n, vector<vector<res>>(n, vector<res>()));
		vector<vector<vector<res>>> tempboard2;
		tempboard2.assign(n, vector<vector<res>>(n, vector<res>()));
		// 이동
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < board[i][j].size(); k++) {
					pair<int,int> res = move(i, j, board[i][j][k].d,board[i][j][k].s,n);
					tempboard[res.first][res.second].push_back({ board[i][j][k].m,board[i][j][k].s,board[i][j][k].d });
				}
			}
		}

		// 하나로 합친다
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				int totalM = 0;
				int totalS = 0;
				int totalK = tempboard[i][j].size();
				if (totalK < 2) {
					tempboard2[i][j] = tempboard[i][j];
					continue;
				}
				vector<int> checkDir = { 0,0,0,0,0,0,0,0 };
				for (int k = 0; k < totalK; k++) {
					totalM += tempboard[i][j][k].m;
					totalS += tempboard[i][j][k].s;
					checkDir[tempboard[i][j][k].d]++;
				}

				int wkr = 0;
				int hal = 0;
				bool check = false;
				for (int k = 0; k < checkDir.size(); k++) {
					if (k % 2 == 0) {
						wkr += checkDir[k];
					}
					else {
						hal += checkDir[k];
					}
				}

				if (wkr > 0 && hal > 0) {
					check = true;
				}

				double newM = totalM / 5.0;
				double newS = totalS / (double)totalK;

				int realNewM = (int)newM;
				int realNewS = (int)newS;

				
				if (realNewM <= 0) {
					continue;
				}
				else {
					if (!check) {
						for (int k = 0; k < 8; k+=2) {
							tempboard2[i][j].push_back({ realNewM,realNewS,k });
						}
					}
					else {
						for (int k = 1; k < 8; k+=2) {
							tempboard2[i][j].push_back({ realNewM,realNewS,k });
						}
					}
				}
			}
		}



		board = tempboard2;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < board[i][j].size(); k++) {
				ans += board[i][j][k].m;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
