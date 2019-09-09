#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
char board[51][51];
bool visited[51][51];
int y,x;
int ans = 3000;
int Ans;
int cnt[2]; // black,white 갯수 체크
bool check,flag;
void go(int nx, int ny) {
	if (nx + 7 > x || ny + 7 > y) return;
	memset(cnt, 0, sizeof(cnt));
	Ans = 0;
	//초기의 black,white값 체크
	for (int i = nx; i <= nx + 7; i++) {
		for (int j = ny; j <= ny + 7; j++) {
			if (board[i][j] == 'B') cnt[0]++;
			else if (board[i][j] == 'W') cnt[1]++;
		}
	}

	//여기서부터 change(왼쪽이 맞다고 가정)
		if (board[nx][ny] == 'B') {
			check = true;
			for (int i = nx; i <= nx + 7; i++){
				if (i >= nx + 1) {
					if (!check) check = true;
					else check = false;
				}
				for (int j = ny; j <= ny + 7; j++) {
					if (visited[i][j] != check) {
						Ans++;
						if (board[i][j] == 'B') { cnt[1]++; cnt[0]--; }
						else if (board[i][j] == 'W') { cnt[1]--; cnt[0]++; }

						if (!check) check = true;
						else check = false;
					}
					else {
						if (!check) check = true;
						else check = false;
					}
				}
			}
		}
		else if (board[nx][ny] == 'W') {
			check = false;
			for (int i = nx; i <= nx + 7; i++){
				if (i >= nx + 1) {
					if (!check) check = true;
					else check = false;
				}
				for (int j = ny; j <= ny + 7; j++) {
					if (visited[i][j] != check) {
						Ans++;
						if (board[i][j] == 'B') { cnt[1]++; cnt[0]--; }
						else if (board[i][j] == 'W') { cnt[1]--; cnt[0]++; }
						if (!check) check = true;
						else check = false;
					}
					else {
						if (!check) check = true;
						else check = false;
					}

				}
			}
		}
		if (cnt[0] == cnt[1])
			ans = min(Ans, ans);

		memset(cnt, 0, sizeof(cnt));
		Ans = 0;
		//초기의 black,white값 체크
		for (int i = nx; i <= nx + 7; i++) {
			for (int j = ny; j <= ny + 7; j++) {
				if (board[i][j] == 'B') cnt[0]++;
				else if (board[i][j] == 'W') cnt[1]++;
			}
		}
		//여기서부터 change(오른쪽이 맞다고 가정)
		if (board[nx][ny] == 'B') {
			check = true;
			for (int i = nx; i <= nx + 7; i++) {
				if (i >= nx + 1) {
					if (!check) check = true;
					else check = false;
				}
				for (int j = ny+7; j >= ny; j--) {
					if (visited[i][j] != check) {
						Ans++;
						if (board[i][j] == 'B') { cnt[1]++; cnt[0]--; }
						else if (board[i][j] == 'W') { cnt[1]--; cnt[0]++; }

						if (!check) check = true;
						else check = false;
					}
					else {
						if (!check) check = true;
						else check = false;
					}
				}
			}
		}
		else if (board[nx][ny] == 'W') {
			check = false;
			for (int i = nx; i <= nx + 7; i++) {
				if (i >= nx + 1) {
					if (!check) check = true;
					else check = false;
				}
				for (int j = ny+7; j>=ny; j--) {
					if (visited[i][j] != check) {
						Ans++;
						if (board[i][j] == 'B') { cnt[1]++; cnt[0]--; }
						else if (board[i][j] == 'W') { cnt[1]--; cnt[0]++; }
						if (!check) check = true;
						else check = false;
					}
					else {
						if (!check) check = true;
						else check = false;
					}

				}
			}
		}
	if (cnt[0] == cnt[1])
		ans = min(Ans, ans);
	return;
}
int main(){
	scanf("%d%d", &x, &y);
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'B') visited[i][j] = true;
			else visited[i][j] = false;
		}
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			go(i, j);
		}
	}
	printf("%d\n", ans);
	return 0;
}