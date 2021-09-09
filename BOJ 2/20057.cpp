#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
// 서(1)남(1)동(2)북(2) ... 서(n-1)
int gox[4] = {0,1,0,-1};
int goy[4] = {-1,0,1,0};
struct p {
	int x, y, percent;
};

int move(int x,int y,vector<vector<p>> &pos, vector<vector<int>> &board) {
	int cnt = 1;
	int n = board.size();
	int ans = 0;
	bool outcheck = false;
	while (true) {
		vector<vector<int>> tempboard = board;
		int nx = x;
		int ny = y;

		//서
		for (int i = 0; i < cnt; i++) {

			nx += gox[0];
			ny += goy[0];
			if (nx == 0 && ny == -1) {
				outcheck = true;
				break;
			}
			int totalSand = tempboard[nx][ny];
			for (int j = 0; j < pos[0].size(); j++) {
				int tx = nx + pos[0][j].x;
				int ty = ny + pos[0][j].y;
				int sand = tempboard[nx][ny] * pos[0][j].percent / 100;
				if (tx >= 0 && tx < n && ty >= 0 && ty < n) tempboard[tx][ty] += sand;
				else ans += sand;
				totalSand -= sand;
				if (j == pos[0].size() - 1) {
					if (tx >= 0 && tx < n && ty >= 0 && ty < n) tempboard[tx][ty] += totalSand;
					else ans += totalSand;
				}
				
			}

			tempboard[nx][ny] = 0;
		}

		if (outcheck) break;

		//남
		for (int i = 0; i < cnt; i++) {


			nx += gox[1];
			ny += goy[1];

			int totalSand = tempboard[nx][ny];
			for (int j = 0; j < pos[1].size(); j++) {
				int tx = nx + pos[1][j].x;
				int ty = ny + pos[1][j].y;
				int sand = tempboard[nx][ny] * pos[0][j].percent / 100;
				if (tx >= 0 && tx < n && ty >= 0 && ty < n) tempboard[tx][ty] += sand;
				else ans += sand;

				totalSand -= sand;
				if (j == pos[1].size() - 1) {
					if (tx >= 0 && tx < n && ty >= 0 && ty < n) tempboard[tx][ty] += totalSand;
					else ans += totalSand;
				}
			}


			tempboard[nx][ny] = 0;

		}

		// 동 
		for (int i = 0; i <= cnt; i++) {

			nx += gox[2];
			ny += goy[2];

			int totalSand = tempboard[nx][ny];
			for (int j = 0; j < pos[2].size(); j++) {
				int tx = nx + pos[2][j].x;
				int ty = ny + pos[2][j].y;
				int sand = tempboard[nx][ny] * pos[0][j].percent / 100;
				if (tx >= 0 && tx < n && ty >= 0 && ty < n) tempboard[tx][ty] += sand;
				else ans += sand;

				totalSand -= sand;
				if (j == pos[0].size() - 1) {
					if (tx >= 0 && tx < n && ty >= 0 && ty < n) tempboard[tx][ty] += totalSand;
					else ans += totalSand;
				}
			}

			tempboard[nx][ny] = 0;
		}
		// 북
		for (int i = 0; i <= cnt; i++) {

			nx += gox[3];
			ny += goy[3];

			int totalSand = tempboard[nx][ny];
			for (int j = 0; j < pos[3].size(); j++) {
				int tx = nx + pos[3][j].x;
				int ty = ny + pos[3][j].y;
				int sand = tempboard[nx][ny] * pos[0][j].percent / 100;
				if (tx >= 0 && tx < n && ty >= 0 && ty < n) tempboard[tx][ty] += sand;
				else ans += sand;
				
				totalSand -= sand;
				if (j == pos[3].size() - 1) {
					if (tx >= 0 && tx < n && ty >= 0 && ty < n) tempboard[tx][ty] += totalSand;
					else ans += totalSand;
				}
			}

			tempboard[nx][ny] = 0;
		}

		cnt+=2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j ++ ) {
				board[i][j] = tempboard[i][j];
			}
		}
		x = nx;
		y = ny;
	}

	return ans;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> board;
	board.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	//시작점 (n/2,n/2)
	vector<vector<p>> pos;
	pos.assign(4, vector<p>(n, {0,0,0}));

	for (int i = 0; i < 4; i++) {
		vector<p> temp;
		if (i == 0) { //서 
			temp.push_back({ -1,1,1 });
			temp.push_back({ 1,1,1 });
			temp.push_back({ -1,0,7 });
			temp.push_back({ 1,0,7 });
			temp.push_back({ -2,0,2 });
			temp.push_back({ 2,0,2 });
			temp.push_back({ -1,-1,10 });
			temp.push_back({ 1,-1,10 });
			temp.push_back({ 0,-2,5 });
			temp.push_back({ 0,-1,0 });
		}
		else if (i == 1) { //남
			temp.push_back({ -1,-1,1 });
			temp.push_back({ -1,1,1 });
			temp.push_back({ 0,-1,7 });
			temp.push_back({ 0,1,7 });
			temp.push_back({ 0,-2,2 });
			temp.push_back({ 0,2,2 });
			temp.push_back({ 1,1,10 });
			temp.push_back({ 1,-1,10 });
			temp.push_back({ 2,0,5 });
			temp.push_back({ 1,0,0 });
		}
		else if (i == 2) { //동
			temp.push_back({ -1,-1,1 });
			temp.push_back({ 1,-1,1 });
			temp.push_back({ -1,0,7 });
			temp.push_back({ 1,0,7 });
			temp.push_back({ -2,0,2 });
			temp.push_back({ 2,0,2 });
			temp.push_back({ -1,1,10 });
			temp.push_back({ 1,1,10 });
			temp.push_back({ 0,2,5 });
			temp.push_back({ 0,1,0 });
		}
		else if (i == 3) { //북
			temp.push_back({ 1,-1,1 });
			temp.push_back({ 1,1,1 });
			temp.push_back({ 0,-1,7 });
			temp.push_back({ 0,1,7 });
			temp.push_back({ 0,-2,2 });
			temp.push_back({ 0,2,2 });
			temp.push_back({ -1,1,10 });
			temp.push_back({ -1,-1,10 });
			temp.push_back({ -2,0,5 });
			temp.push_back({ -1,0,0 });
		}
		pos[i] = temp;
	}


	printf("%d\n",move(n/2,n/2,pos,board));

	return 0;
}