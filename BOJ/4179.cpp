#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
/*
struct PP {
int r, c;
};
*/
vector<vector<int>> a;
queue<P> q;
P Board[1000000];
int n, m, idx, idy, firex, firey, k;
int answer = 99999999;
char board[1001][1001];
char moveboard[1001][1001];
bool visited[1001][1001];//불이 방문한곳
bool visited2[1001][1001];// J가 방문한곳
bool flag;
int cnt[1001][1001];
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
void bfs(int a, int b) {
	visited[a][b] = true;
	// 불저지르고
	while (!q.empty()) {
		while (!q.empty()) {
			Board[k] = q.front();
			int x = Board[k].first;
			int y = Board[k].second;
			if (visited2[x][y]) break; // J방문
			q.pop();
			//불지르기
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>n)continue;
				if (board[x][y] == 'F' && board[nx][ny] != '#' && !visited[nx][ny]) {
					q.push({ nx,ny });
					board[nx][ny] = 'F';
					visited[nx][ny] = true;
				}
			}
		}
		//이동
		k++;
		while (!q.empty()) {
			Board[k] = q.front();
			int x = Board[k].first;
			int y = Board[k].second;
			if (visited[x][y] && !visited2[x][y]) break; //불방문,본인이 방문이되어있다그러면 이동할수있는거지(불부터지르니까)
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (board[nx][ny] == '.' && board[nx][ny] != 'F' &&board[nx][ny] != '#' && !visited[nx][ny]) {
					q.push({ nx,ny });
					board[nx][ny] = 'J';
					visited2[nx][ny] = true;
					cnt[nx][ny] = cnt[x][y] + 1;
				}
			}
		}
	}
	k++;
}
//이동
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			moveboard[i][j] = board[i][j];
			if (board[i][j] == 'J')
			{
				idx = i;
				idy = j;
				visited2[idx][idy] = true;
			}
			if (board[i][j] == 'F') {
				visited[i][j] = true;
				firex = i;
				firey = j;
				q.push({ i, j }); //불위치넣기
			}
		}
	}
	q.push({ idx,idy });
	for (int i = 1; i <= m; i++) {
		if (idx == 1 && idy == m) flag = true;
		if (idx == n && idy == 1) flag = true;
	}
	for (int i = 1; i <= n; i++) {
		if (idx == i && idy == 1) flag = true;
		if (idx == i && idy == m) flag = true;
	}
	if(!flag)
	bfs(firex, firey);
	for (int i = 1; i <= m; i++) {
		if (cnt[1][i] == 0) continue;
		answer = min(cnt[1][i], answer);
	}
	for (int i = 1; i <= m; i++) {
		if (cnt[n][i] == 0) continue;
		answer = min(cnt[n][i], answer);
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i][1] == 0) continue;
		answer = min(cnt[i][1], answer);
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i][m] == 0) continue;
		answer = min(cnt[i][m], answer);
	}
	if (flag) answer = 0;
	if (answer != 99999999)
		printf("%d\n", answer + 1);
	else
		printf("IMPOSSIBLE\n");
	return 0;
}