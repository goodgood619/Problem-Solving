#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <deque>
using namespace std;
int gox[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int goy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
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
bool check(int x,int y, vector<pair<int,int>> &cloud) {
	bool checkCloud = false;
	for (int i = 0; i < cloud.size(); i++) {
		if (cloud[i].first == x && y == cloud[i].second) {
			checkCloud = true;
			break;
		}
	}
	return checkCloud;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int>> board;
	board.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	vector<pair<int, int>> cloud = { {n - 1,0},{n - 1,1},{n - 2,0},{n - 2,1} };
	for (int i = 0; i < m; i++) {
		int d, s;
		scanf("%d%d", &d, &s);

		// 모든 구름이 전체 d방향으로 s번 이동한다.
		
		vector<pair<int, int>> tempcloud;
		for(int i=0;i<cloud.size();i++){
			pair<int, int> res = move(cloud[i].first,cloud[i].second,d,s,n);
			tempcloud.push_back({ res.first,res.second });
		}

		vector<vector<int>> tempboard = board;

		// 물이 한칸씩 증가
		for (int i = 0; i < tempcloud.size(); i++) {
			tempboard[tempcloud[i].first][tempcloud[i].second]++;
		}

		//물복사

		for (int i = 0; i < tempcloud.size(); i++) {
			int x = tempcloud[i].first;
			int y = tempcloud[i].second;
			int waterCnt = 0;
			for (int j = 2; j <= 8; j += 2) {
				int nx = x + gox[j];
				int ny = y + goy[j];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n || tempboard[nx][ny]==0) continue;
				waterCnt++;
			}

			tempboard[x][y] += waterCnt;
		}

		// 물이 2이상이면 모든 칸에 구름이 생김, 단 예전 구름의 위치는 아니어야함
		vector<pair<int, int>> realcloud;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check(i, j, tempcloud) || tempboard[i][j]<2) continue;
				tempboard[i][j] -= 2;
				realcloud.push_back({ i,j });
			}
		}

		cloud = realcloud;
		board = tempboard;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += board[i][j];
		}
	}

	printf("%d\n", ans);
	return 0;
}