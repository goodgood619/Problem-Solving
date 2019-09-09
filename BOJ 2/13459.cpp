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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, rx, ry, bx, by, ex, ey;
char board[15][15];
int check(int x, int y, int dir) {
	int length = 0;
	for (int i = 1;; i++) {
		int nx = x + i * gox[dir];
		int ny = y + i * goy[dir];
		if (board[nx][ny] == 'R' || board[nx][ny] == 'B') { // 빨강공이나 파랑공이면, 길이 더해주고 건너뛰기
			length++;
			continue;
		}
		if (board[nx][ny] == '#') return length; // 벽을만났거나
		if (board[nx][ny] == 'O') { // 구멍을 만나면, 그 길이값까지 더해준후 반환
			length++;
			return length;
		}
		length++;
	}

}
bool check2(int rx, int ry, int bx, int by) {
	if (rx == bx && ry == by && board[rx][ry] != 'O') return true; // 좌표는 같은데, 구멍이 아니어야함. 구멍이면 둘다 들어갈수 있기 때문임
	else return false;
}
int go(int rx, int ry, int bx, int by, int cnt) {
	if (cnt >= 11) return 1e9;// 10번이상은 불가능
	if (rx == ex && ry == ey && (bx != ex || by != ey)) return 0; // 빨간색만 구멍속으로 들어간경우
	else if (rx == ex && ry == ey && bx == ex && by == ey) return 1e9; // 둘다 들어간경우
	else if ((rx != ex || ry != ey) && bx == ex && by == ey) return 1e9; // 파란색만 들어간경우(이걸 안해줘서 틀렸었음)
	int ret = 1e9;
	for (int i = 0; i < 4; i++) {
		int length1 = check(rx, ry, i);
		int length2 = check(bx, by, i);
		if (i == 0) { //동쪽
			if (check2(rx, ry + length1, bx, by + length2)) { // 좌표가 겹치는지 안겹치는지확인
				if (ry < by) length1--; // 빨간색이 더 작았다면, 동쪽으로 움직였으므로, 빨간색 길이값을 줄여줘야한다
				else length2--;
			}
			ret = min(ret, go(rx, ry + length1, bx, by + length2, cnt + 1) + 1);
		}
		else if (i == 1) { // 남쪽
			if (check2(rx + length1, ry, bx + length2, by)) {
				if (rx < bx) length1--;
				else length2--;
			}
			ret = min(ret, go(rx + length1, ry, bx + length2, by, cnt + 1) + 1);
		}
		else if (i == 2) { //북쪽
			if (check2(rx - length1, ry, bx - length2, by)) {
				if (rx < bx) length2--;
				else length1--;
			}
			ret = min(ret, go(rx - length1, ry, bx - length2, by, cnt + 1) + 1);
		}
		else { //서쪽
			if (check2(rx, ry - length1, bx, by - length2)) {
				if (ry < by) length2--;
				else length1--;
			}
			ret = min(ret, go(rx, ry - length1, bx, by - length2, cnt + 1) + 1);
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'R') rx = i, ry = j;
			if (board[i][j] == 'B') bx = i, by = j;
			if (board[i][j] == 'O') ex = i, ey = j;
		}
	}

	int ans = go(rx, ry, bx, by, 0);
	ans == 1e9 ? printf("0\n") : printf("1\n");
	return 0;
}