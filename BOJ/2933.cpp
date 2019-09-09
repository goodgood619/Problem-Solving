#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int r, c, n, idx, idy;
typedef pair <int, int > P;
bool check, aircluster;
vector<vector<int>> airclusterspot;
char board[105][105];
bool visited[105][105];
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
void go(int floor, bool check) {
	if (!check) {
		for (int j = 1; j <= c; j++) {
			if (board[r + 1 - floor][j] == '.') continue;
			else {
				idx = r + 1 - floor;
				idy = j;
				break;
			}
		}
	}
	else {
		for (int j = c; j >= 1; j--) {
			if (board[r + 1 - floor][j] == '.') continue;
			else {
				idx = r + 1 - floor;
				idy = j;
				break;
			}
		}
	}
}
void bfs(int x, int y){
	int aircnt = 0;
	int noaircnt = 0;
	queue <P> q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>r || ny<1 || ny>c || visited[nx][ny] || board[nx][ny] == '.') continue;
			else if (!visited[nx][ny] && board[nx][ny] == 'x') {
				if (aircluster) {
					airclusterspot[ny].push_back(-nx);
					visited[nx][ny] = true;
					q.push({ nx,ny });
					aircnt++;
				}
				else {
					visited[nx][ny] = true;
					q.push({ nx,ny });
					noaircnt++;
				}
			}
		}
	}
	if (aircnt == 0 && noaircnt==0) {
		airclusterspot[y].push_back(-x);
	}
}
void move(){
	for (int i = 1; i <= c; i++) {
		sort(airclusterspot[i].begin(), airclusterspot[i].end());
	}
	int Check = 0;
	int dot = 9999999;
	for (int j = 1; j <= c; j++) {
		if (airclusterspot[j].size() == 0) continue;
		for (int i = 0; i < airclusterspot[j].size(); i++) {
			int firstx = abs(airclusterspot[j][0]);
			int x = abs(airclusterspot[j][i]);
			int y = j;
			if (Check == y) continue;
			else {
				Check = y;
				int tempdot = 0;
				for (int k = firstx + 1;k<=r;k++){
					if (board[k][y] == '.') {
						tempdot++;
						continue;
					}
					else break;
				}
				dot = min(tempdot, dot);
			}
		}
	}

	for (int j = 1; j <= c; j++) {
		if (airclusterspot[j].size() == 0) continue;
		for (int i = 0; i < airclusterspot[j].size(); i++) {
			int x = abs(airclusterspot[j][i]);
			int y = j;
			board[x + dot][y] = board[x][y];
			board[x][y] = '.';
		}
	}
}

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	scanf("%d", &n);
	airclusterspot.resize(c + 1);
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		idx = 0;
		idy = 0;
		int floor;
		scanf("%d", &floor);
		go(floor, check);
		if (!check) check = true;
		else check = false;
		board[idx][idy] = '.';
		aircluster = false;
		for (int k = r; k >= 1; k--) {
			for (int j = 1; j <= c; j++) {
				if (board[k][j] == '.') continue;
				if (!visited[k][j] && board[k][j] == 'x' && k == r) {
					bfs(k, j);
				}
				else if (!visited[k][j] && board[k][j] == 'x' && k != r) {
					aircluster = true;
					bfs(k, j);
					break;
				}
			}
			if (aircluster) break;
		}
		if (aircluster) {
			move();
			airclusterspot.clear();
			airclusterspot.resize(c + 1);
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}