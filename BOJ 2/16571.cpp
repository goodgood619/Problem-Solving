#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
int board[3][3];
bool visited[9];
int my[3], opponent[3];
struct p {
	int x, y;
};
bool check(int turn)
{
	// 가로
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != turn) break;

			if (j == 2) return true;
		}
	}

	// 세로
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (board[i][j] != turn) break;

			if (i == 2) return true;
		}
	}

	// 오른쪽 아래 대각선
	for (int i = 0; i < 3; i++)
	{
		if (board[i][i] != turn) break;

		if (i == 2) return true;
	}

	// 왼쪽 아래 대각선
	for (int i = 0; i < 3; i++)
	{
		if (board[i][2 - i] != turn) break;

		if (i == 2) return true;
	}

	return false;
}
int go(int turn,vector<p> &v,int origin) {
	if (check(3-turn)) {
		return -1;
	}
	int Min = 2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 0) {
				board[i][j] = turn;
				Min = min(Min, go(turn == 2 ? 1 : 2, v, origin));
				board[i][j] = 0;
			}
		}
	}
	if (Min == 2 || Min == 0) return 0;
	return -Min;
}
int main(){
	int one = 0, two = 0,cnt=0;
	vector<p> v;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 1) one++;
			else if (board[i][j] == 2) two++;
			else {
				v.push_back({ i,j });
				cnt++;
			}
		}
	}
	// 2번이 착수할 플레이어
	if (one > two) {
		int ans = go(2,v,2);
		if (ans == 1) printf("W");
		else if (ans == 0) printf("D");
		else printf("L");
	}
	//1번이 착수할 플레이어
	else {
		int ans= go(1,v,1);
		if (ans == 1) printf("W");
		else if (ans == 0) printf("D");
		else printf("L");
	}
	return 0;
}